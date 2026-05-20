
#include "ignore.kd.h"
#include "KT.h"
template<> void mainSet(
    const std::string &key,
    bool value
) {
    KT.KDController.set(KT.mainCtrl(), key.c_str(), KT.boolToAny(value));
}

template<> void mainSet(
    const std::string &key,
    const char *value
) {
    KT.KDController.set(KT.mainCtrl(), key.c_str(), KT.strToAny(value));
}

void API::mainSet(const QString &key, const QVariant &value) {
    auto skey = key.toStdString();
    auto type = value.userType();

    // Bool
    if (type == QMetaType::Bool) {
        ::mainSet(skey, value.toBool());
    }
    // QString
    else if (type == QMetaType::QString) {
        ::mainSet(skey, value.toString().toStdString().c_str());
    }
    // Unknown
    else {
        printf("ERR UI.mainS unknown type for key '%s'\n", skey.c_str());
    }
}

bool MainContext::didClickChangeText() {
    return KT.MainContext.get_didClickChangeText(ctx);
}

bool MainContext::didLaunch() {
    return KT.MainContext.get_didLaunch(ctx);
}

bool MainContext::didSetup() {
    return KT.MainContext.get_didSetup(ctx);
}

QString MainContext::greetingText() const & {
    const char *raw = KT.MainContext.get_greetingText(ctx);
    QString str(raw);
    KTSym->DisposeString(raw);
    return str;
}

bool MainContext::isVisible() {
    return KT.MainContext.get_isVisible(ctx);
}

std::vector<std::any> MainEffectRegistry::_items;

void MainEffectRegistry::processOneliners() {
    auto mainCtx = KT.mainCtrlCtx();
    auto recentField = KT.mainCtrlCtxField();

    int halfCount = _items.size() / 2;
    for (int i = 0; i < halfCount; ++i) {
        auto effectField = std::any_cast<const char *>(_items[i * 2]);
        if (strcmp(effectField, recentField) == 0) {
            auto callback = std::any_cast<std::function<void(MainContext)>>(_items[i * 2 + 1]);
            auto c = MainContext(mainCtx);
            callback(c);
        }
    }

    KTSym->DisposeString(recentField);
}

void MainEffectRegistry::registerOneliners(
    KTRef(KDController) ctrl,
    const std::vector<std::any> &items
) {
    // This should only be run once. Yes, it's ugly
    // but it keeps API consistent with other platforms.
    KT.registerCallbackC(
        ctrl,
        (void *)&MainEffectRegistry::processOneliners
    );
    _items = items;
}
