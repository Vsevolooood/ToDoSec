/****************************************************************************
** Meta object code from reading C++ file 'VM.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/VM.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VM.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN2VME_t {};
} // unnamed namespace

template <> constexpr inline auto VM::qt_create_metaobjectdata<qt_meta_tag_ZN2VME_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "VM",
        "mainDidChangeIsVisible",
        "",
        "value",
        "mainDidChangeTaskTitle",
        "tasksChanged",
        "mainSetIsVisible",
        "mainSetTaskTitle",
        "mainSettaskTitle",
        "addTask",
        "task",
        "addAllTasks",
        "tasks",
        "std::vector<std::string>",
        "removeTask",
        "index",
        "clearTasks",
        "mainIsVisible",
        "mainTaskTitle"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'mainDidChangeIsVisible'
        QtMocHelpers::SignalData<void(bool)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 3 },
        }}),
        // Signal 'mainDidChangeTaskTitle'
        QtMocHelpers::SignalData<void(const QString &)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'tasksChanged'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'mainSetIsVisible'
        QtMocHelpers::SlotData<void(bool)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 3 },
        }}),
        // Slot 'mainSetTaskTitle'
        QtMocHelpers::SlotData<void(const QString &)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'mainSettaskTitle'
        QtMocHelpers::SlotData<void(const QString &)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'addTask'
        QtMocHelpers::SlotData<void(const QString &)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 10 },
        }}),
        // Slot 'addAllTasks'
        QtMocHelpers::SlotData<void(const QStringList &)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QStringList, 12 },
        }}),
        // Slot 'addAllTasks'
        QtMocHelpers::SlotData<void(const std::vector<std::string> &)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 13, 12 },
        }}),
        // Slot 'removeTask'
        QtMocHelpers::SlotData<void(int)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 15 },
        }}),
        // Slot 'clearTasks'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'mainIsVisible'
        QtMocHelpers::PropertyData<bool>(17, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable, 0),
        // property 'mainTaskTitle'
        QtMocHelpers::PropertyData<QString>(18, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable, 1),
        // property 'tasks'
        QtMocHelpers::PropertyData<QStringList>(12, QMetaType::QStringList, QMC::DefaultPropertyFlags, 2),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<VM, qt_meta_tag_ZN2VME_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject VM::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2VME_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2VME_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2VME_t>.metaTypes,
    nullptr
} };

void VM::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<VM *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->mainDidChangeIsVisible((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->mainDidChangeTaskTitle((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->tasksChanged(); break;
        case 3: _t->mainSetIsVisible((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 4: _t->mainSetTaskTitle((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->mainSettaskTitle((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->addTask((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->addAllTasks((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 8: _t->addAllTasks((*reinterpret_cast<std::add_pointer_t<std::vector<std::string>>>(_a[1]))); break;
        case 9: _t->removeTask((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->clearTasks(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (VM::*)(bool )>(_a, &VM::mainDidChangeIsVisible, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (VM::*)(const QString & )>(_a, &VM::mainDidChangeTaskTitle, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (VM::*)()>(_a, &VM::tasksChanged, 2))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->mainIsVisible(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->mainTaskTitle(); break;
        case 2: *reinterpret_cast<QStringList*>(_v) = _t->tasks(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->mainSetIsVisible(*reinterpret_cast<bool*>(_v)); break;
        case 1: _t->mainSetTaskTitle(*reinterpret_cast<QString*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *VM::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VM::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2VME_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int VM::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void VM::mainDidChangeIsVisible(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void VM::mainDidChangeTaskTitle(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void VM::tasksChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
