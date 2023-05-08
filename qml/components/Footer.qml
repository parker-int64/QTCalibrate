pragma Singleton

import QtQuick
import FluentUI

FluObject{

    id:footer_items

    FluPaneItemSeparator{}

    FluPaneItem{
        title:"关于"
        cusIcon: Image{
                   anchors.centerIn: parent
                   source: "/images/info_circle.svg"
                   sourceSize: Qt.size(30,30)
                   width: 18
                   height: 18
         }
        onTap:{
            FluApp.navigate("/about")
        }
    }
}
