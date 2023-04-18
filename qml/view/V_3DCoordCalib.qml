import QtQuick
import QtQuick.Layouts
import QtQuick.Window
import QtQuick.Controls
import FluentUI
import Qt.CalibCoord 0.1


FluScrollablePage {

    leftPadding: 10
    rightPadding: 0
    bottomPadding: 20
    title: "3D坐标系标定"

    CalibCoord {
        id: calib

        onCalibError: {
            showError("标定失败，请检查数据是否正确")
        }

        onCalibSuccess: {
            showSuccess("完成!")
        }
    }


    ColumnLayout {

        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        Layout.fillWidth: true
        Layout.fillHeight: true

        FluText {
            text: "使用OpenCV中的各种功能，计算三维关系转换。"
            fontStyle: FluText.Body
        }


        FluFilledButton {
            id: clearBtn
            text: "清除输入"
            onClicked: {

            }
        }


    }



}
