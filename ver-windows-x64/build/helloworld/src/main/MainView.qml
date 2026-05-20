import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Rectangle {
    id: mainView
    anchors.fill: parent
    visible: vm.mainIsVisible

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 16

        // Строка ввода сверху и во всю ширину
        TextField {
            id: taskInput

            Layout.fillWidth: true
            Layout.alignment: Qt.AlignTop

            placeholderText: "Задача"

            // Чтение из VM
            text: vm.mainTaskTitle

            // Запись через mainSet()
            onTextChanged: {
                api.mainSet(F.taskTitle, text)
            }

            onAccepted: {
                api.mainSet(F.didClickSaveText, true)
            }
        }
    }
}