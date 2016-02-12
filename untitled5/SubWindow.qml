import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

Rectangle {
//ApplicationWindow {
    id: root
    visible: true
    width: 400
    height: 300
    //title: qsTr("Hello World")
    Button {
        id: button1

        iconSource: "imgs/LogoTE-Mid.png"
        text: "Voltar"
    }
    /*toolBar: ToolBar {
        width: parent.width
        height: parent.height

        RowLayout{
            id: rowLayout1

            Button {
                id: button1

                iconSource: "imgs/LogoTE-Mid.png"
                text: "Voltar"
                onClicked: root.close()
            }
            Button {
                text: "Push Me"
            }
        }
    }*/
}

