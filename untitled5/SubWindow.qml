import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1

SubWindowForm {



    // @disable-check M16
    toolBar: ToolBar {
        /*Image {
            source: "/imgs/Logo/SplashScreen.png"

        }*/
        RowLayout{
            Button {
                anchors.centerIn: parent
                text: "Push Me"
            }
            Button {
                anchors.centerIn: parent
                text: "Push Me"
            }
        }
    }
}

