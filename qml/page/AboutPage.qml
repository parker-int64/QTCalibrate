import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import FluentUI

FluWindow {

    width: 300
    height: 400
    minimumWidth: 300
    minimumHeight: 400
    maximumWidth: 300
    maximumHeight: 400

    title:"关于"

    FluAppBar{
        id:appbar
        title:"关于"
        width:parent.width
    }

    ColumnLayout{
        Layout.alignment: Qt.AlignCenter


        RowLayout {
            Layout.alignment: Qt.AlignHCenter
            Layout.leftMargin: 20
            Layout.topMargin: 20
            FluText {
                text: "Mini Vision Toolbox，部分组件版本如下："
            }

        }

        ColumnLayout {
            Layout.fillWidth: true
            Layout.topMargin: 20
            Layout.alignment: Qt.AlignCenter
            spacing: 10


            Image {
                Layout.alignment: Qt.AlignHCenter
                Layout.preferredWidth:  64
                Layout.preferredHeight: 64
                source: "qrc:/images/qt_logo.png"
                mipmap: true
                antialiasing: true
                fillMode: Image.PreserveAspectFit
            }

            FluText {
                Layout.alignment: Qt.AlignHCenter
                text: "Qt 6"
            }


            Image {
                Layout.alignment: Qt.AlignHCenter
                Layout.preferredWidth:  64
                Layout.preferredHeight: 64
                source: "qrc:/images/opencv_logo.png"
                mipmap: true
                antialiasing: true
                fillMode: Image.PreserveAspectFit
            }



            FluText{
                Layout.alignment: Qt.AlignHCenter
                text:"OpenCV 4"
            }

        }


        RowLayout {
            Layout.topMargin: 20
            Layout.leftMargin: 20
            Layout.alignment: Qt.AlignHCenter
            spacing: 10
            FluText {
                width: parent.width
                pixelSize: 10
                text: "*部分素材来源于互联网\n\n如果感觉本软件有帮助，还请留一个免费的Star"
            }

            Image {
                Layout.alignment: Qt.AlignHCenter
                Layout.preferredWidth:  32
                Layout.preferredHeight: 32
                source: "qrc:/images/github_logo.png"
                mipmap: true
                antialiasing: true
                fillMode: Image.PreserveAspectFit

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        Qt.openUrlExternally("https://github.com/parker-int64/QTCalibrate")
                    }
                }
            }

        }
    }
}
