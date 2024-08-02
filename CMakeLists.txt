cmake_minimum_required(VERSION 3.19)
project(EKGViewer VERSION 1.0 LANGUAGES CXX)

# Set C++20 standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find Qt6 packages
find_package(Qt6 REQUIRED COMPONENTS Core Gui Quick Qml)
if (NOT Qt6_FOUND)
    message(FATAL_ERROR "Qt6 not found. Please ensure Qt6 is installed correctly.")
endif()

# Find QWT package
find_package(QWT REQUIRED)
if (NOT QWT_FOUND)
    message(FATAL_ERROR "QWT not found. Please ensure QWT is installed correctly.")
endif()

# Define the sources and headers
set(SOURCES
    main.cpp
    ekgmodel.cpp
    ekgviewmodel.cpp
)

set(HEADERS
    ekgmodel.h
    ekgviewmodel.h
)

# Define the QML resource file
set(QML_FILES
    qml.qrc
)

# Create the executable target
add_executable(EKGViewer
    ${SOURCES}
    ${HEADERS}
    ${QML_FILES}
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

# Ensure QML resources are built
qt_add_resources(EKGViewer
    PREFIX "/"
    FILES
    ${QML_FILES}
)

# Set the RPATH to find Qt6 and QWT libraries at runtime
set_target_properties(EKGViewer PROPERTIES
    INSTALL_RPATH_USE_LINK_PATH TRUE
)

# Display diagnostic information
message(STATUS "Qt6 Version: ${Qt6_VERSION}")
message(STATUS "QWT Version: ${QWT_VERSION}")
