import QtQuick
import QtQuick.Controls

Window {
    width: 1280
    height: 720
    visible: true
    title: qsTr("Serial Plot")

    ComboBox{
        model: ["patates", "cilek",  "patlıcan"]

    }
}
