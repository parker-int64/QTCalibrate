import QtQuick
import QtQuick.Layouts
import QtQuick.Window
import QtQuick.Controls
import FluentUI
import Qt.labs.qmlmodels

import Qt.DataTrans 0.1


FluScrollablePage {

    leftPadding: 10
    rightPadding: 10
    bottomPadding: 20
    title: "九点手眼标定"


    ColumnLayout {

        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        Layout.fillWidth: true
        Layout.fillHeight: true

        FluArea {
            paddings: 10
            Layout.fillWidth: true
            height: 50
            FluText {
                anchors.verticalCenter: parent.verticalCenter
                text: "使用OpenCV的estimateAffine2D函数，计算两个二维点集之间的最佳仿射变换。"
                fontStyle: FluText.Body
            }
        }





        FluArea {

            paddings: 10
            Layout.fillWidth: true
            height: 400


            FluText {
                anchors.horizontalCenter: parent.horizontalCenter
                text: "相机像素点信息"
                fontStyle: FluText.BodyStrong
            }


            Item {

                id: inputPoints1
                anchors.centerIn: parent
                Layout.fillWidth: true
                Layout.fillHeight: true

                ColumnLayout {
                    anchors.centerIn: parent
                    Layout.alignment: Qt.AlignHCenter
                    spacing: 10
                    Layout.fillWidth: true
                    Layout.leftMargin: 10

                    Repeater {
                        id: cameraPointsRepeater
                        model: 9
                        delegate: RowLayout {

                            spacing: 10

                            FluText {
                                Layout.alignment: Qt.AlignVCenter
                                text: "Point " + (index + 1)
                            }

                            FluTextBox {
                                Layout.preferredWidth: 150
                                placeholderText: "0.000"
                            }

                            FluTextBox {
                                Layout.preferredWidth: 150
                                placeholderText: "0.000"
                            }

                        }
                    }
                }
            }
        }



        FluArea {

            paddings: 10
            Layout.fillWidth: true
            height: 400


            FluText {
                anchors.horizontalCenter: parent.horizontalCenter
                text: "机器人点位信息"
                fontStyle: FluText.BodyStrong
            }


            Item {

                id: inputPoints2
                anchors.centerIn: parent
                Layout.fillWidth: true
                Layout.fillHeight: true

                ColumnLayout {
                    anchors.centerIn: parent
                    Layout.alignment: Qt.AlignHCenter
                    spacing: 10
                    Layout.fillWidth: true
                    Layout.leftMargin: 10

                    Repeater {
                        id: robotPointsRepeater
                        model: 9
                        delegate: RowLayout {

                            spacing: 10

                            FluText {
                                Layout.alignment: Qt.AlignVCenter
                                text: "Point " + (index + 1)
                            }

                            FluTextBox {
                                Layout.preferredWidth: 150
                                placeholderText: "0.000"
                            }

                            FluTextBox {
                                Layout.preferredWidth: 150
                                placeholderText: "0.000"
                            }

                        }
                    }
                }
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
                    console.log(_x1.text)
                }
            }

            FluFilledButton {
                id: exeCalib
                text: "执行"
                onClicked: {
                    showInfo("执行中")
//                    resultDialog.open()
                    getInputBoxData()
                }


                DataTrans {
                    id: dataTrans
                }

                function getInputBoxData() {

                    var data = []
                    let  rgx = /^[0-9.-]+$/;  // numeric only

                    for(let i = 0; i < 9; i++) {

                        // pointsets 1
                        let _x1 = cameraPointsRepeater.itemAt(i).children[1].text
                        let _y1 = cameraPointsRepeater.itemAt(i).children[2].text

                        // pointsets 2
                        let _x2 = robotPointsRepeater.itemAt(i).children[1].text
                        let _y2 = robotPointsRepeater.itemAt(i).children[2].text


                        // exceptions
                        if( _x1.length === 0 || _x2.length === 0 || _y1.length === 0 || _y2.length === 0){
                            showError("输入数据不能为空!")
                            data = []
                            break
                        }
                        else if ( !rgx.test(_x1) || !rgx.test(_x2) || !rgx.test(_y1) || !rgx.test(_y2)) {
                            showError("输入仅能包含数字，小数点和负号!")
                            data = []
                            break
                        }

                        // push data
                        data.push(_x1, _y1, _x2, _y2)

                    }

                    if( data.length !== 0 ){
                        dataTrans.getDataFromQml(data)
                    }

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


