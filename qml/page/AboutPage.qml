import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import FluentUI

FluWindow {

    width: 500
    height: 600
    minimumWidth: 500
    minimumHeight: 600
    maximumWidth: 500
    maximumHeight: 600

    title:"关于"

    FluAppBar{
        id:appbar
        title:"关于"
        width:parent.width
    }

    ColumnLayout{
        anchors{
            top: appbar.bottom
            left: parent.left
            right: parent.right
        }


        RowLayout {
            Layout.topMargin: 20
            Layout.leftMargin: 15
            spacing: 14
            FluText {
                text: "一个相机标/坐标系的标定程序，部分组件版本如下："
            }

        }

        RowLayout {
            Layout.topMargin: 20
            Layout.leftMargin: 15
            spacing: 14
            FluText {
                text: "Qt"
            }

            FluText {
                text: "6.2 LTS"
                fontStyle: FluText.Body
                Layout.alignment: Qt.AlignBottom
            }
        }

        RowLayout{
            Layout.topMargin: 20
            Layout.leftMargin: 15
            spacing: 14
            FluText{
                text:"FluentUI"
            }
            FluText{
                text:"v1.1.9"
                fontStyle: FluText.Body
                Layout.alignment: Qt.AlignBottom
            }
        }

        RowLayout{
            Layout.topMargin: 20
            Layout.leftMargin: 15
            spacing: 14
            FluText{
                text:"OpenCV"
            }
            FluText{
                text:"4.x"
                fontStyle: FluText.Body
                Layout.alignment: Qt.AlignBottom
            }
        }
    }
}
