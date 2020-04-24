cmake_minimum_required(VERSION 3.5)

project(Calibration LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(EXECUTABLE_OUTPUT_PATH ../bin)
# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
find_package(OpenCV REQUIRED)
set(TS_FILES ${CMAKE_CURRENT_SOURCE_DIR}/Calibration_zh_CN.ts)
qt5_create_translation(QM_FILES ${CMAKE_CURRENT_LIST_DIR} ${TS_FILES})
add_executable(Calibration WIN32)
set_property(TARGET Calibration PROPERTY WIN32_EXECUTABLE true)

target_sources(Calibration
                PUBLIC
                    ${CMAKE_CURRENT_SOURCE_DIR}/include/mainwindow.h
                    ${CMAKE_CURRENT_SOURCE_DIR}/include/dialog.h
                PRIVATE
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/mainwindow.cpp
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/dialog.cpp
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/dialog.ui
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/mainwindow.ui
                    ${CMAKE_CURRENT_SOURCE_DIR}/uiComponents.qrc
                    ${CMAKE_CURRENT_SOURCE_DIR}/app.rc

                )
target_include_directories(Calibration
                            PUBLIC
                                ${CMAKE_CURRENT_LIST_DIR}/include
                                ${OpenCV_INCLUDE_DIRS}
                            )
target_link_libraries(Calibration
                        PRIVATE
                            Qt5::Widgets
                            ${OpenCV_LIBS}
                            )

