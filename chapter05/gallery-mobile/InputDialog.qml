import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Window 2.3


Dialog {
    property string label: "new item"
    property string hint: ""
    property alias editText: editTextItem

    standardButtons: StandardButtons.ok | StandardButtons.Cancel

    onVisibleChanged: {
        editTextItem.focus = true
        editTextItem.selectAll()
    }

    onButtonClicked: {
        Qt.inputMethod.hide();
    }

    Rectangle {
        implicitHeight: 100
        implicitWidth: parent.width

        ColumnLayout {
            Text {
                id: labelItem
                text: label
                color: Style.text
            }

            TextInput {
                id: editTextItem
                inputMethodHints: Qt.ImhPreferUppercase
                text: hint
                color: Style.text
            }
        }
    }

}
