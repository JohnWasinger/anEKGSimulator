cmake_minimum_required(VERSION 3.10)

project(EKG_MVVM)

set(CMAKE_CXX_STANDARD 13)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Core Gui Qml Quick Widgets)
find_package(Qwt REQUIRED)

add_executable(EKG_MVVM
    src/main.cpp
    src/ekgmodel.cpp
    src/ekgviewmodel.cpp
    src/ekgcontroller.cpp
    src/ekgplot.cpp
)

target_link_libraries(EKG_MVVM
    Qt5::Core
    Qt5::Gui
    Qt5::Qml
    Qt5::Quick
    Qt5::Widgets
    Qwt::Qwt
)

set_target_properties(EKG_MVVM PROPERTIES
    AUTOMOC ON
    AUTORCC ON
    AUTOUIC ON
)

qt5_add_resources(EKG_MVVM_RCC_FILES resources.qrc)
