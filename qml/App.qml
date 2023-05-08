import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import FluentUI

Window {
    id:app
    color: "#00000000"
    Component.onCompleted: {
        FluApp.init(app)
        FluTheme.frameless = ("windows" === Qt.platform.os)
        FluTheme.darkMode = FluDarkMode.System
        FluApp.routes = {
            "/":"qrc:/Calibration/qml/window/MainWindow.qml",
            "/about": "qrc:/Calibration/qml/window/AboutWindow.qml",
        }
        FluApp.initialRoute = "/"
        FluApp.run()
    }

}
