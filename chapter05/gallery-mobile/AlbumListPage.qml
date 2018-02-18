import QtQuick 2.9
import QtQuick.Controls 2.2
import "." 1.0


PageTheme {
    toolBarTitle: "Albums"
    toolBarButtons: ToolButton {
        background: Image {
            source: "qrc:/res/icons/album-add.svg"
        }

        onClicked: {
            newAlbumDialog.open()
        }
    }

    InputDialog {
        id: newAlbumDialog
        title: "New album"
        label: "Album name:"
        hint: "My album"

        onAccepted: {
            albumModel.addAlbumFromName(editText.text)
        }
    }

    ListView {
        id: albumList
        model: albumModel
        spacing: 5
        anchors.fill: parent

        delegate: Rectangle {
            width: parent.width
            height: 120
            color: Style.buttonBackground

            Text {
                text: name
                font.pointSize: 16
                color: Style.text
                anchors.verticalCenter: parent.verticalCenter
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    albumList.currentIndex = index
                    pictureModel.setAlbumId(id)
                    pageStack.push("qrc:/AlbumPage.qml",
                                   { albumName: name, albumRowIndex: index })
                }
            }
        }
    }
}
