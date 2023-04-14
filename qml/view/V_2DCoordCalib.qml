import QtQuick
import QtQuick.Layouts
import QtQuick.Window
import QtQuick.Controls
import FluentUI
import Qt.labs.qmlmodels
import Qt.CalibCoord 0.1

import "qrc:///qml/components"


FluScrollablePage {

    leftPadding: 10
    rightPadding: 10
    bottomPadding: 20
    title: "九点手眼标定"


    FluPivot {

        id: pivotView
        Layout.fillWidth: true
        height: 1000
        FluPivotItem {
            title: "填写数据"
            contentItem:
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
                        id: cls
                        width: 75
                        height: 45
                        text: "清除输入"
                        onClicked: {
                            clearInputs()
                        }

                        function clearInputs(){
                            for(let i = 0; i < 9; i++) {

                                // pointsets 1
                                let _x1 = cameraPointsRepeater.itemAt(i).children[1].text = ""
                                let _y1 = cameraPointsRepeater.itemAt(i).children[2].text = ""

                                // pointsets 2
                                let _x2 = robotPointsRepeater.itemAt(i).children[1].text = ""
                                let _y2 = robotPointsRepeater.itemAt(i).children[2].text = ""
                            }

                            showSuccess("完成!")
                        }
                    }

                    CalibCoord {

                        id: calib

                        onCalibError: {
                            showCalibErrorInfo()
                        }

                        onCalibResultChanged: {
                            showCalibResult()
                        }


                        function showCalibErrorInfo() {
                            showError("标定失败，请检查数据是否正确")
                        }

                        function showCalibResult(){
                            var data = calib.getCalibResult()

                            for(let i in data){
                                // TODO Defination probrem
                                // 定义在这之后的id无法使用
                                resultRepeater.itemAt(i).children[1].text = data[i]

                            }

                        }


                    }

                    FluFilledButton {
                        id: exeCalib
                        text: "执行"
                        onClicked: {
                            showInfo("执行中")
                            getInputBoxData()

                        }


                        function getInputBoxData() {

                            var data = []
                            let  rgx = /^[0-9.-]+$/;  // numeric only

        //                    for(let i = 0; i < 9; i++) {

        //                        // pointsets 1
        //                        let _x1 = cameraPointsRepeater.itemAt(i).children[1].text
        //                        let _y1 = cameraPointsRepeater.itemAt(i).children[2].text

        //                        // pointsets 2
        //                        let _x2 = robotPointsRepeater.itemAt(i).children[1].text
        //                        let _y2 = robotPointsRepeater.itemAt(i).children[2].text


        //                        // exceptions
        //                        if( _x1.length === 0 || _x2.length === 0 || _y1.length === 0 || _y2.length === 0){
        //                            showError("输入数据不能为空!")
        //                            data = []
        //                            break
        //                        }
        //                        else if ( !rgx.test(_x1) || !rgx.test(_x2) || !rgx.test(_y1) || !rgx.test(_y2)) {
        //                            showError("输入仅能包含数字，小数点和负号!")
        //                            data = []
        //                            break
        //                        }

        //                        // push data
        //                        data.push(_x1, _y1, _x2, _y2)

        //                    }

        //                    if( data.length !== 0 ){
        //                        calib.get2DData(data)
        //                    }

                            //Test Only
                            calib.get2DData(data)

                        }
                    }
                }
            }
        }

        FluPivotItem {
            title: "仿射变换矩阵结果"
            contentItem:
            ColumnLayout {
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                Layout.fillWidth: true
                height: 300

                FluArea {
                    id: hintArea
                    paddings: 10
                    Layout.fillWidth: true
                    height: 50
                    FluText {
                        id: hintText
                        anchors.verticalCenter: parent.verticalCenter
                        text: "以下是仿射变换矩阵，单击选框以复制到剪切板"
                        fontStyle: FluText.Body
                    }
                }

                FluArea {

                    paddings: 10

                    width: parent.width
                    height: parent.height

                    FluText {
                        width: parent.width - 20
                        id: principleHints
                        fontStyle: FluText.BodyStrong
                        wrapMode: Text.WordWrap
                        Component.onCompleted: {
                            principleHints.text = "estimateAffine2D Computes an optimal limited affine transformation with 4 degrees of freedom between two 2D point sets. The computed transformation is then refined further (using only inliers) with the Levenberg-Marquardt method to reduce the re-projection error even more."
                                                + "\n"
                                                + "Note The RANSAC method can handle practically any ratio of outliers but need a threshold to distinguish inliers from outliers. The method LMeDS does not need any threshold but it works correctly only when there are more than 50% of inliers.\n\n"
                        }
                    }


                    ColumnLayout {
                        anchors.top:  principleHints.bottom
                        anchors.horizontalCenter: parent.horizontalCenter
                        spacing: 10
                        Layout.fillWidth: true
                        Layout.leftMargin: 10
                        Layout.topMargin: 30

                        Repeater {
                            id: resultRepeater
                            model: 6
                            delegate: RowLayout {
                                spacing: 10
                                FluText {
                                    Layout.alignment: Qt.AlignVCenter
                                    text: "Transformation " + (index + 1) + ":"
                                }

                                FluTextBox {
                                    iconSource: FluentIcons.Copy
                                    Layout.preferredWidth: 150
                                    placeholderText: "0.000"
                                    selectByMouse: false
                                    MouseArea {
                                        anchors.fill: parent
                                        cursorShape: Qt.PointingHandCursor
                                        onClicked: {
                                            showSuccess("已复制！")
                                            FluApp.clipText(parent.text)
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}


