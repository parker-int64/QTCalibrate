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

    FluArea {
        Layout.fillWidth: true
        height: 100

        RowLayout {
            spacing: 10
            anchors.fill: parent


            FluText {
                text: "导出的JSON文件"
                Layout.leftMargin: 10
                Layout.alignment: Qt.AlignVCenter | Qt.AlignLeft
            }

            FluTextBox{
                Layout.alignment: Qt.AlignCenter
                iconSource: FluentIcons.FolderOpen
                Layout.preferredWidth: 300
                placeholderText: "选择导出后的JSON文件"
                selectByMouse: false

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {
                        console.log("Choose json file")
                    }
                }
            }
        }


    }


    FluArea {
        Layout.fillWidth: true
        height: 100



        RowLayout {

            spacing: 10
            anchors.fill: parent


            FluText {
                text: "生成txt的目录"
                Layout.leftMargin: 10
                Layout.alignment: Qt.AlignVCenter | Qt.AlignLeft
            }

            FluTextBox{
                Layout.alignment: Qt.AlignCenter
                iconSource: FluentIcons.FolderOpen
                Layout.preferredWidth: 300
                placeholderText: "选择生成txt的目录"
                selectByMouse: false

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {
                        console.log("Choose a directory file")
                    }
                }
            }
        }

    }



    FluArea {
        Layout.fillWidth: true
        height: 100



        ColumnLayout{

            anchors.verticalCenter: parent.verticalCenter
            FluText {
                Layout.preferredWidth: 600
                Layout.alignment: Qt.AlignVCenter
                Layout.leftMargin: 10
                text: "说明:此功能需要先使用Label-studio导出YOLO的数据集，而后导出含有BBox和Key Points的JSON文件,当读取完JSON文件后，对其进行解析，会将读取到的Key Points位 置信息写入YOLO训练集的txt（需提供txt目录）中"
                wrapMode: Text.WordWrap
            }

            FluText {
                Layout.alignment: Qt.AlignVCenter
                Layout.leftMargin: 10
                fontStyle: FluText.BodyStrong
                text: "如需了解详细转换信息，请参考帮助文档"
            }
        }


    }
}
