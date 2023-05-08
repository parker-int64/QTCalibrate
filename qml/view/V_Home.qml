import QtQuick
import QtQuick.Layouts
import QtQuick.Window
import QtQuick.Controls
import FluentUI
import Calibration


FluScrollablePage {
    leftPadding:10
    rightPadding:0
    bottomPadding:20

    // head info part
    ListModel{
        id: model_header
        ListElement{
            icon:"/images/cam.svg"
            title:"相机标定"
            desc:"快速实现基于OpenCV的单目、双目标定"
            url:"https://github.com"
        }
    }


    Item {
        id: item1
        Layout.fillWidth: true
        height: 320
        Image {
            fillMode: Image.PreserveAspectCrop
            anchors.fill: parent
            verticalAlignment: Qt.AlignTop
            source: "/images/bg_mojave.jpg"
        }

        // Use the rectangle for gradient style
        Rectangle{
            anchors.fill: parent
            gradient: Gradient{
                GradientStop { position: 0.8; color: FluTheme.dark ? Qt.rgba(0,0,0,0) : Qt.rgba(1,1,1,0) }
                GradientStop { position: 1.0; color: FluTheme.dark ? Qt.rgba(0,0,0,1) : Qt.rgba(1,1,1,1) }
            }
        }


        RowLayout {
            FluText {
                text:"Mini Vision Toolbox"
                fontStyle: FluText.TitleLarge
                color: "#000000"
                Layout.alignment: Qt.AlignLeft
                Layout.topMargin: 20
                Layout.leftMargin: 20
            }
        }
    }
}
