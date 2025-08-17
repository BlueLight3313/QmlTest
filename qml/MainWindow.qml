import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    width: 800
    height: 450
    color: "lightgreen"

    Text {
        anchors.centerIn: parent
        text: "Hello QML!"
        font.pixelSize: 20
        color: "darkblue"
    }

    Button {
        text: "Click me!"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 30

        onClicked: {
            console.log("Button clicked!");
        }
    }
}
