cmake_minimum_required(VERSION 3.16)

project(calibration VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 14)

find_package(Qt6 REQUIRED COMPONENTS Quick Core Quick QuickControls2)


find_package(OpenCV REQUIRED COMPONENTS core calib3d)

include_directories(${OpenCV_INCLUDE_DIRS})
set(SOURCES
    src/calibcoord.h
    src/calibcoord.cpp
    src/main.cpp)

set(RESOURCES qml.qrc)
set(RC_ICONS icons/favicon.ico)


add_executable(${PROJECT_NAME} ${SOURCES} ${RESOURCES} ${RC_ICONS})

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
