import QtQuick 2.4

SplashForm {
    id: splashForm1
    Image {
        id: image1
        x: 98
        y: 125
        width: 205
        height: 150
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        fillMode: Image.PreserveAspectFit
        source: "Logo/SplashScreen.png"
    }
}

