import QtQuick 2.5

Rectangle {
    color: "gray"
    height: 50
    Rectangle {
        id: purpleRectangle
        width: 50; height: parent.height
        color: "purple"
        radius: 10
    }

    Text {
        anchors.left: purpleRectangle.right
        anchors.right: parent.right
        text: "Dominate the mobile ui"
        font.pointSize: 30
    }
}
