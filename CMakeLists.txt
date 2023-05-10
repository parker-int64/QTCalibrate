cmake_minimum_required(VERSION 3.16)

project(calibration VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 14)

find_package(Qt6 REQUIRED COMPONENTS Quick Core Quick QuickControls2)


find_package(OpenCV REQUIRED COMPONENTS core calib3d)

include_directories(./include
    ${OpenCV_INCLUDE_DIRS})


set(SOURCES
    include/cvfunctions.h
    include/calibcoord.h
    src/cvfunctions.cpp
    src/calibcoord.cpp
    src/main.cpp
)

set(RESOURCES qml.qrc)
set(RC_ICONS icons/favicon.ico)


set(QML_FILES qml/components/Footer.qml
              qml/components/Sidebar.qml
              qml/window/AboutWindow.qml
              qml/window/MainWindow.qml
              qml/view/Test.qml
              qml/view/V_2DCoordCalib.qml
              qml/view/V_3DCoordCalib.qml
              qml/view/V_Home.qml
              qml/view/V_JSONConverter.qml
              qml/view/V_Settings.qml
              qml/App.qml)

set_source_files_properties(qml/components/Footer.qml
                            qml/components/Sidebar.qml
                            PROPERTIES
                            QT_QML_SINGLETON_TYPE TRUE
)

file(GLOB IMAGE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/images/*.png"
                      "${CMAKE_CURRENT_SOURCE_DIR}/images/*.svg"
                      "${CMAKE_CURRENT_SOURCE_DIR}/images/*.jpg")





qt_add_executable(${PROJECT_NAME} ${SOURCES})


qt_add_qml_module(${PROJECT_NAME}
    URI Calibration
    VERSION 1.0
    QML_FILES ${QML_FILES})


# images
qt_add_resources(${PROJECT_NAME} "images"
                PREFIX "/images"
                BASE "images"
                FILES ${IMAGE_FILES})


# program icons
qt_add_resources(${PROJECT_NAME} "icons"
                PREFIX "/icons"
                BASE "icons"
                FILES ${RC_ICONS})



set_target_properties(${PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
    Qt6::Core
    Qt6::Quick
    Qt6::QuickControls2
    ${OpenCV_LIBS}
)


if(WIN32)
    target_compile_definitions(${PROJECT_NAME} PRIVATE UNICODE WIN32 _WINDOWS)
    target_link_libraries(${PROJECT_NAME} PRIVATE dwmapi user32)
endif()

install(TARGETS ${PROJECT_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
