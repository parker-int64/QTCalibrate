import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import FluentUI

Window {
    id:app
    color: "#00000000"
    Component.onCompleted: {
        FluApp.init(app,properties)
        FluTheme.frameless = ("windows" === Qt.platform.os)
        FluTheme.dark = false
        FluApp.routes = {
            "/":"qrc:/qml/page/MainPage.qml",
            "/about": "qrc:/qml/page/AboutPage.qml",
        }
        FluApp.initialRoute = "/"
        FluApp.run()


    }

}
