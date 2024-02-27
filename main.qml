import QtQuick
import QtQuick.Controls
import Moon
import QtQuick.Controls.Material

Window {
    width: 1280
    height: 720
    visible: true
    title: qsTr("Serial Plot")

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
        model: serialManager.detectedComs;

        onCurrentTextChanged: {
            console.log(cmbPort.currentText)
            serialManager.setComName(cmbPort.currentText)

        }

    }
}
