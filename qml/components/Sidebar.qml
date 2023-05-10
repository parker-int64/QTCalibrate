pragma Singleton

import QtQuick
import FluentUI


FluObject{

    property var navigationView


    FluPaneItem{
        title:"Home"
        icon:FluentIcons.Home
        onTap:{
            navigationView.push("/Calibration/qml/view/V_Home.qml")
        }
    }


    FluPaneItemExpander{
        title: "相机标定"
        icon: FluentIcons.Camera
        FluPaneItem{
            title:"单目相机"
            onTap:{
                navigationView.push("/Calibration/qml/view/Test.qml")
            }
        }

        FluPaneItem{
            title:"双目相机"
            onTap:{
                navigationView.push("/Calibration/qml/view/Test.qml")
            }
        }
    }


    FluPaneItemExpander{
        title: "坐标系标定"
        icon: FluentIcons.Add
        FluPaneItem{
            title:"九点手眼标定"
            cusIcon: Image{
                       anchors.centerIn: parent
                       source: FluTheme.dark ? "/images/circle_grid_icon_dark.svg" :  "/images/circle_grid_icon.svg"
                       sourceSize: Qt.size(30,30)
                       width: 18
                       height: 18
             }
            onTap:{
                navigationView.push("/Calibration/qml/view/V_2DCoordCalib.qml")
            }
        }

        FluPaneItem{
            title:"3D坐标"
            cusIcon: Image{
                       anchors.centerIn: parent
                       source: "/images/chessboard_icon.svg"
                       sourceSize: Qt.size(30,30)
                       width: 18
                       height: 18
             }
            onTap:{
                navigationView.push("/Calibration/qml/view/V_3DCoordCalib.qml")
            }
        }
    }



    FluPaneItem{
        title:"测试页"
        icon:FluentIcons.Edit
        onTap:{
            navigationView.push("/Calibration/qml/view/Test.qml")
        }
    }

    FluPaneItem{
        title:"Annotation JSON文件转换"
        cusIcon: Image{
                   anchors.centerIn: parent
                   source:  FluTheme.dark ? "/images/json_icon_dark.svg" : "/images/json_icon.svg"
                   sourceSize: Qt.size(30,30)
                   width: 18
                   height: 18
         }
        onTap:{
            navigationView.push("/Calibration/qml/view/V_JSONConverter.qml")
        }
    }


    FluPaneItem{
        title:"设置"
        icon:FluentIcons.Settings
        onTap:{
            navigationView.push("/Calibration/qml/view/V_Settings.qml")
        }
    }

    function getSearchData(){
        var arr = []
        var items = navigationView.getItems();
        for(var i=0;i<items.length;i++){
            var item = items[i]
            if(item instanceof FluPaneItem){
                arr.push({title:item.title,key:item.key})
            }
        }
        return arr
    }

    function startPageByItem(data){
        var items = navigationView.getItems();
        for(var i=0;i<items.length;i++){
            var item =  items[i]
            if(item.key === data.key){
                if(navigationView.getCurrentIndex() === i){
                    return
                }
                item.tap()
                navigationView.setCurrentIndex(i)
                if(item.parent){
                    item.parent.isExpand = true
                }
                return
            }
        }
    }

}
