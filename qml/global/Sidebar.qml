pragma Singleton

import QtQuick
import FluentUI


FluObject{

    property var navigationView

    FluPaneItem{
        title:"Home"
        icon:FluentIcons.Home
        onTap:{
            navigationView.push("qrc:/qml/view/V_Home.qml")
        }
    }


    FluPaneItemExpander{
        title: "相机标定"
        icon: FluentIcons.Camera
        FluPaneItem{
            title:"单目相机"
            onTap:{
                navigationView.push("qrc:/qml/view/Test.qml")
            }
        }

        FluPaneItem{
            title:"双目相机"
            onTap:{
                navigationView.push("qrc:/qml/view/Test.qml")
            }
        }
    }


    FluPaneItemExpander{
        title: "坐标系标定"
        icon: FluentIcons.Add
        FluPaneItem{
            title:"2D坐标"
            onTap:{
                navigationView.push("qrc:/qml/view/V_2DCoordCalib.qml")
            }
        }

        FluPaneItem{
            title:"3D坐标"
            onTap:{
                navigationView.push("qrc:/qml/view/V_3DCoordCalib.qml")
            }
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
