import QtQuick
import QtQuick.Layouts
import QtQuick.Window
import QtQuick.Controls
import FluentUI
import Qt.labs.qmlmodels


FluScrollablePage {

    leftPadding: 10
    rightPadding: 0
    bottomPadding: 20
    title: "3D坐标系标定"


    ColumnLayout {

        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        Layout.fillWidth: true
        Layout.fillHeight: true

        FluText {
            text: "使用OpenCV中的各种功能，计算三维关系转换。"
            fontStyle: FluText.Body
        }


    }



}
