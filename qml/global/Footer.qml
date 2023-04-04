pragma Singleton

import QtQuick
import FluentUI

FluObject{
    id:footer_items
    FluPaneItemSeparator{}
    FluPaneItem{
        title:"关于"
        onTap:{
            FluApp.navigate("/about")
        }
    }
}
