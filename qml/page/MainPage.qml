import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import "qrc:///qml/global/"
import FluentUI

FluWindow {
    id:rootwindow
    width: 1000
    height: 640
    title: "CalibrationApp"
    minimumWidth: 560
    minimumHeight: 460

    FluAppBar{
        id:appbar
        z:10
        showDark: true
        width:parent.width
    }

    FluNavigationView{
        id:nav_view
        anchors.fill: parent
        items: Sidebar
        footerItems: Footer
        logo: "qrc:/icons/favicon.ico"
        z: 11
        title:"CalibrationApp"
        autoSuggestBox:FluAutoSuggestBox{
            width: 280
            anchors.centerIn: parent
            iconSource: FluentIcons.Zoom
            items: Sidebar.getSearchData()
            placeholderText: "查找"
            onItemClicked:
                (data)=>{
                    Sidebar.startPageByItem(data)
                }
        }
        Component.onCompleted: {
            Sidebar.navigationView = nav_view
            nav_view.setCurrentIndex(0)
            nav_view.push("qrc:/qml/view/V_Home.qml")
        }
    }

}
