import QtQuick
import QtQuick.Controls
import QtQuick.Window




Item {
    property int dialogWidth: 400
    property int dialogHeight: 300
    property bool dialogResult: true

    property bool okButtonEnable: true
    property bool confirmButtonEnable: false
    property bool cancelButtonEnable: false

    property real expectContentWidth: 400
    property real expectContentHeight: 300

    property string innerText: ""
    id: dialogRoot
    width: dialogWidth
    height: dialogHeight

    Rectangle {
        id: background
        width: parent.width
        height: parent.height
        color: "#ffffff"

        Pane {
            id: pane
            width: parent.width - 20
            height: parent.height - 100
            anchors.top: parent.top
            anchors.topMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter

            Flickable {
                id: flick
                width: parent.width
                height: parent.height
                contentWidth: expectContentWidth
                contentHeight: expectContentHeight
                clip: true
                enabled: expectContentHeight <= 300 ? false : true
                flickableDirection:  Flickable.VerticalFlick // vertical operations only
                ScrollBar.vertical:  ScrollBar {
                    id: vbar
                    hoverEnabled: true
                    active: hovered || pressed
                    orientation: Qt.Vertical
                    size: 0.5
                    anchors.top: parent.top
                    anchors.right: parent.right
                    anchors.bottom: parent.bottom
                }

                Rectangle {
                    width: parent.width
                    height: 300
                    TextField {
                        id: dialogText
                        width: parent.width
                        text: innerText

                        clip: true

                        selectByMouse: true

                        anchors.verticalCenter: parent.verticalCenter

                        anchors.horizontalCenter: parent.horizontalCenter

                     }
                    MouseArea {
                        anchors.fill: parent
                        cursorShape: Qt.IBeamCursor
                        acceptedButtons: Qt.NoButton
                    }
                }


            }
        }

        Rectangle {
            id: footerRect
            width: parent.width
            height: 50
            color: "#f3f4f6"
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0

            Button {
                id: confirmButton
                text: qsTr("Confirm")
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: cancelButton.left
                font.pixelSize: 14
                anchors.rightMargin: 20
                anchors.verticalCenterOffset: 0
                highlighted: true
                flat: false
                font.weight: Font.Bold
                font.underline: false
                font.bold: false

                visible: confirmButtonEnable ? true : false
                onClicked: {
                    // confirm button will return true
                    dialogResult = true
                    dialogPopup.close()
                    return dialogResult
                }
            }

            Button {
                id: cancelButton
                text: qsTr("Cancel")
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                font.pixelSize: 14
                wheelEnabled: false
                highlighted: false
                flat: false
                font.weight: Font.Bold

                anchors.rightMargin: 20
                visible: cancelButtonEnable ? true : false
                onClicked: {
                    // cancel button will return false
                    dialogResult = false
                    dialogPopup.close()
                    return dialogResult
                }
            }

            Button {
                id: okButton
                text: qsTr("OK")
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 14

                font.weight: Font.Bold
                highlighted: true
                anchors.horizontalCenter: parent.horizontalCenter
                visible: okButtonEnable ? true : false
                onClicked: {
                    // This default dialog button returns nothing
                    dialogPopup.close()
                }
            }
        }
    }
}
