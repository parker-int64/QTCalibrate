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
                   source: FluTheme.dark ?  "/images/info_circle_icon_dark.svg" : "/images/info_circle_icon.svg"
                   sourceSize: Qt.size(30,30)
                   width: 18
                   height: 18
         }
        onTap:{
            FluApp.navigate("/about")
        }
    }
}
