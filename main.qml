import QtQuick
import QtQuick.Controls
import Moon
import QtQuick.Controls.Material

Window {
    id: root
    width: 1280
    height: 720
    visible: true
    title: qsTr("Serial Plot")


    property bool connectStatus: false

    //theme colors
    Material.accent:  "#0E1C22"
    Material.background: "#A08F64"

    SerialManager{
        id: serialManager
    }


    ComboBox{
        id: cmbPort
        anchors.centerIn: parent
        //Add Com names in combobox
        model: serialManager.detectedComs

        onCurrentTextChanged: {
            console.log(cmbPort.currentText)
            serialManager.setComName(cmbPort.currentText)

        }
        Text{
            anchors{
                bottom: parent.top
                left: parent.left
            }
            font.pixelSize:13
            text: "Com Name:"
            font.bold: false

        }

    }
    ComboBox{

        id: cmbBaud
        anchors{
            top: cmbPort.bottom
            topMargin: 30
            horizontalCenter: cmbPort.horizontalCenter
        }

        model: ListModel{
            ListElement { baud: 9600 }
            ListElement { baud: 19200 }
            ListElement { baud: 38400 }
        }
        textRole: "baud"

        onCurrentTextChanged: {
            console.log(cmbBaud.currentText)
            serialManager.setBaudRate(cmbPort.currentText)
        }

        Text{
            anchors{
                bottom: parent.top
                left: parent.left
            }
            font.pixelSize:13
            text: "Baud Rate:"
            font.bold: false

        }

    }

    Button{
        id: btn_ConDiscon
        //TO:DO Look for colors
        Material.background: serialManager.connectStatus ? "#A08F64" : "#0E1C22"
        Material.foreground: serialManager.connectStatus ? "#0E1C22" : "#A08F64"

        anchors{
            top: cmbBaud.bottom
            topMargin: 10
            horizontalCenter: cmbBaud.horizontalCenter

        }
        text: serialManager.connectStatus ? "Disconnect" : "Connect"

        onClicked: {
            console.log("Connect Status: ", serialManager.connectStatus)
            if(serialManager.connectStatus == false){
                console.log("Clicked: true")
                // connectStatus = true;
                // I am not changing the status here, as it miight be possible that port
                // didn't opened, so it will be updated in the emitted signal
                serialManager.setConnectStatus(true);
            }
            else{
                console.log("Clicked: false")
                // connectStatus = false;
                // I am not changing the status here, as it miight be possible that port
                // didn't opened, so it will be updated in the emitted signal
                serialManager.setConnectStatus(false)
            }
        }
    }
}
