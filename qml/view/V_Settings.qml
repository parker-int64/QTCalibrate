import QtQuick
import QtQuick.Layouts
import QtQuick.Window
import QtQuick.Controls
import FluentUI
import Calibration

FluScrollablePage{

    title: "设置"
    leftPadding:10
    rightPadding:10
    bottomPadding:20
    spacing: 0

    FluArea{
        Layout.fillWidth: true
        Layout.topMargin: 20
        height: 136
        paddings: 10

        ColumnLayout{
            spacing: 10
            anchors{
                top: parent.top
                left: parent.left
            }
            FluText{
                text: "深色模式"
                fontStyle: FluText.BodyStrong
                Layout.bottomMargin: 4
            }
            Repeater{
                model: [
                    {
                        title: "跟随系统",
                        mode:FluDarkMode.System
                    },

                    {
                        title: "浅色",
                        mode:FluDarkMode.Light
                    },

                    {
                        title: "深色",
                        mode:FluDarkMode.Dark
                    }
                ]
                delegate:  FluRadioButton{
                    selected : FluTheme.darkMode === modelData.mode
                    text: modelData.title
                    onClicked:{
                        FluTheme.darkMode = modelData.mode
                    }
                }
            }


        }

    }

}
