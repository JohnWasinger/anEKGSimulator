cmake_minimum_required(VERSION 3.19)  # Required for CMake 3.19 or newer
project(EKGViewer VERSION 1.0 LANGUAGES CXX)

# Set C++20 standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find Qt6
find_package(Qt6 REQUIRED COMPONENTS Core Gui Quick Qml)

# Find QWT
find_package(QWT REQUIRED)

# Define the sources
set(SOURCES
    main.cpp
    ekgmodel.cpp
    ekgviewmodel.cpp
)

# Define the header files
set(HEADERS
    ekgmodel.h
    ekgviewmodel.h
)

# Create the executable target
add_executable(EKGViewer
    ${SOURCES}
    ${HEADERS}
    qml.qrc  # QML resources file
)

# Link against Qt6 libraries
target_link_libraries(EKGViewer
    PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Quick
    Qt6::Qml
    QWT::QWT
)

# Include directories for Qt6 and QWT
target_include_directories(EKGViewer
    PRIVATE
    ${Qt6_INCLUDE_DIRS}
    ${QWT_INCLUDE_DIRS}
)

# Set up QML resources
qt_add_qml_module(EKGViewer
    URI EKGViewer
    VERSION 1.0
    QML_FILES
    Main.qml
)

# Set the RPATH to find Qt6 and QWT libraries at runtime
set_target_properties(EKGViewer PROPERTIES
    INSTALL_RPATH_USE_LINK_PATH TRUE
)

# Ensure QML modules are built
qt_add_resources(EKGViewer
    PREFIX
    "/"
    FILES
    qml.qrc
)
