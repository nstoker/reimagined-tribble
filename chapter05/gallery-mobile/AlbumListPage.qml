import QtQuick 2.9
import QtQuick.Controls 2.2
// import "." // This might be needed https://bugreports.qt.io/browse/QTBUG-34418


PageTheme {
    toolBarTitle: "Albums"

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
                text: qsTr("name")
                font.pointSize: 16
                color: Style.text
                anchors.verticalCenter: parent.verticalCenter
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    albumList.currentIndex = index
                    pictureModel.setAlbumId(id)
                    pageStack.push("qrc:/qml/AlbumPage.qml",
                                   { albumName: name, albumRowIndex: index })
                }
            }
        }
    }
}
