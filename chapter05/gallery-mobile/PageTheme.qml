import QtQuick 2.0

import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
// import "." // This might be needed https://bugreports.qt.io/browse/QTBUG-34418

Page {
    property alias toolBarButtons: buttonsLoader.sourceComponent
    property alias toolBarTitle: titleLabel.text

    header: ToolBarTheme {
        RowLayout {
            anchors.fill: parent
            ToolButton {
                background: Image{
                    source: "qrc:/res/icons/back.svg"
                }
                onClicked: {
                    if(stackView.depth > 1) {
                        stackView.pop()
                    }
                }
            }

            Label {
                id: titleLabel
                Layout.fillWidth: true
                color: Style.text
                elide: Text.ElideRight
                font.pointSize: 30
            }

            Loader {
                Layout.alignment: Qt.AlignRight
                id: buttonsLoader
            }
        }
    }

    Rectangle {
        color: Style.pageBackground
        anchors.fill: parent
    }
}
