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
    title: "2D坐标系标定"

    ColumnLayout {

        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        Layout.fillWidth: true
        Layout.fillHeight: true

        FluText {
            text: "使用OpenCV的estimateAffine2D函数，计算两个二维点集之间的最佳仿射变换。"
            fontStyle: FluText.Body
        }

        FluText {
            Layout.topMargin: 10
            text: "第一组点位信息"
            fontStyle: FluText.Body
        }


        GridLayout {
            rows: 4
            columns: 3

            Layout.alignment: Qt.AlignHCenter
            Layout.fillWidth: true
            Layout.fillHeight: true

            FluTextBox {
                Layout.row: 1
                Layout.column: 1
                Layout.topMargin: 10
                Layout.preferredWidth: 200
                placeholderText: "第1组，第1个点的X"
            }

            FluTextBox {
                Layout.row: 1
                Layout.column: 2
                Layout.topMargin: 10
                Layout.preferredWidth: 200
                placeholderText: "第1组，第1个点的Y"
            }

            FluTextBox {
                Layout.row: 2
                Layout.column: 1
                Layout.topMargin: 10
                Layout.preferredWidth: 200
                placeholderText: "第1组，第2个点的X"
            }

            FluTextBox {
                Layout.row: 2
                Layout.column: 2
                Layout.topMargin: 10
                Layout.preferredWidth: 200
                placeholderText: "第1组，第2个点的Y"
            }

            FluTextBox {
                Layout.row: 3
                Layout.column: 1
                Layout.topMargin: 10
                Layout.preferredWidth: 200
                placeholderText: "第1组，第3个点的X"
            }

            FluTextBox {
                Layout.row: 3
                Layout.column: 2
                Layout.topMargin: 10
                Layout.preferredWidth: 200
                placeholderText: "第1组，第3个点的Y"
            }

            FluTextBox {
                Layout.row: 4
                Layout.column: 1
                Layout.topMargin: 10
                Layout.preferredWidth: 200
                placeholderText: "第1组，第4个点的X"
            }

            FluTextBox {
                Layout.row: 4
                Layout.column: 2
                Layout.topMargin: 10
                Layout.preferredWidth: 200
                placeholderText: "第1组，第4个点的Y"
            }
        }



        FluText {
            Layout.topMargin: 10
            text: "第二组点位信息"
            fontStyle: FluText.Body
        }

        GridLayout {
            rows: 4
            columns: 3
            Layout.alignment: Qt.AlignHCenter
            Layout.fillWidth: true
            Layout.fillHeight: true

            FluTextBox {
                Layout.row: 1
                Layout.column: 1
                Layout.topMargin: 10
                Layout.preferredWidth: 200
                placeholderText: "第2组，第1个点的X"
            }

            FluTextBox {
                Layout.row: 1
                Layout.column: 2
                Layout.topMargin: 10
                Layout.preferredWidth: 200
                placeholderText: "第2组，第1个点的Y"
            }

            FluTextBox {
                Layout.row: 2
                Layout.column: 1
                Layout.topMargin: 10
                Layout.preferredWidth: 200
                placeholderText: "第2组，第2个点的X"
            }

            FluTextBox {
                Layout.row: 2
                Layout.column: 2
                Layout.topMargin: 10
                Layout.preferredWidth: 200
                placeholderText: "第2组，第2个点的Y"
            }

            FluTextBox {
                Layout.row: 3
                Layout.column: 1
                Layout.topMargin: 10
                Layout.preferredWidth: 200
                placeholderText: "第2组，第3个点的X"
            }

            FluTextBox {
                Layout.row: 3
                Layout.column: 2
                Layout.topMargin: 10
                Layout.preferredWidth: 200
                placeholderText: "第2组，第3个点的Y"
            }

            FluTextBox {
                Layout.row: 4
                Layout.column: 1
                Layout.topMargin: 10
                Layout.preferredWidth: 200
                placeholderText: "第2组，第4个点的X"
            }

            FluTextBox {
                Layout.row: 4
                Layout.column: 2
                Layout.topMargin: 10
                Layout.preferredWidth: 200
                placeholderText: "第2组，第4个点的Y"
            }
        }


        RowLayout {
            id: buttonFuntions
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignRight
            Layout.topMargin: 20
            spacing: 20
            FluButton {
                id: clearInputs
                width: 75
                height: 45
                text: "清除输入"
                onClicked: {
                    showInfo("已清除")
                }
            }

            FluFilledButton {
                id: exeCalib
                text: "执行"
                onClicked: {
                    showInfo("执行中")
                    resultDialog.open()
                }
            }
        }


        TableView {

            columnSpacing: 1
            rowSpacing: 1
            clip: true

            model: TableModel {
                TableModelColumn { display: "name" }
                TableModelColumn { display: "color" }

                rows: [
                    {
                        "name": "cat",
                        "color": "black"
                    },
                    {
                        "name": "dog",
                        "color": "brown"
                    },
                    {
                        "name": "bird",
                        "color": "white"
                    }
                ]
            }

            delegate: Rectangle {
                implicitWidth: 100
                implicitHeight: 50
                border.width: 1

                Text {
                    text: display
                    anchors.centerIn: parent
                }
            }
        }


    }


    property bool resultReady: false
    FluContentDialog {
        id: resultDialog
        title: "进行中"
        message: "正在进行计算"
        negativeText:"取消"

    }






}
