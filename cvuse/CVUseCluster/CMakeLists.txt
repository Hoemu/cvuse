cmake_minimum_required(VERSION 3.16)

project(DemoUseCluster VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(USE_DEPENDS ON) # 设置依赖（如果不能运行，关闭此依赖）

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Core Network REQUIRED)  # Qt6 写法
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets )
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

#if(USE_DEPENDS)
#    include(./depends/depends_setting.cmake)
#endif()
#find_package(OpenCV REQUIRED)

include(./code-config/base-config.cmake)


set(PROJECT_SOURCES
    main.cpp
    # logic
    Remote/config_setting.h Remote/config_setting.cpp
    Remote/remote_udp.h Remote/remote_udp.cpp
    Remote/remote_tcp.h Remote/remote_tcp.cpp

    # UI
    UI/mainwindow.cpp UI/mainwindow.h UI/mainwindow.ui
    UI/udp_page.h UI/udp_page.cpp UI/udp_page.ui
    UI/tcp_page.h UI/tcp_page.cpp UI/tcp_page.ui
    # ${acore_src}
    UI/remote
    # 其他
    UiHeader
)

add_definitions(-DSOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR})


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(DemoUseCluster
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET DemoUseCluster APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(DemoUseCluster SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(DemoUseCluster
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(DemoUseCluster PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt6::Core
    Qt6::Network
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.DemoUseCluster)
endif()
set_target_properties(DemoUseCluster PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS DemoUseCluster
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(DemoUseCluster)
endif()
