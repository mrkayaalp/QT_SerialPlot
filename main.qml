import QtQuick
import QtQuick.Controls
import Moon
Window {
    width: 1280
    height: 720
    visible: true
    title: qsTr("Serial Plot")

    SerialManager{
        id: serialManager
    }

    ComboBox{
        model: ["patates", "cilek",  "patlıcan"]

    }
}
