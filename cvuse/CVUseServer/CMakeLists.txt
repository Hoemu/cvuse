cmake_minimum_required(VERSION 3.16)

project(CVUseServer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(USE_DEPENDS ON) # 设置依赖（如果不能运行，关闭此依赖）

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Core Network REQUIRED)  # Qt6 写法
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets )
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

if(USE_DEPENDS)
    include(./depends/depends_setting.cmake)
endif()
find_package(OpenCV REQUIRED)


set(PROJECT_SOURCES
    main.cpp
    # logic
    win/win_opengl.h win/win_opengl.cpp
    win/win_play.h win/win_play.cpp
    protocol/protocol_udp.h protocol/protocol_udp.cpp
    tool/qss_tool.h tool/qss_tool.cpp

    # UI
    winUI/mainwindow.cpp winUI/mainwindow.h winUI/mainwindow.ui
    winUI/main_page.cpp winUI/main_page.h winUI/main_page.ui
    winUI/setting_page.h winUI/setting_page.cpp winUI/setting_page.ui
    winUI/other_page.h winUI/other_page.cpp winUI/other_page.ui
    winUI/component/win_title.h winUI/component/win_title.cpp winUI/component/win_title.ui
    winUI/component/button_text_group.h winUI/component/button_text_group.cpp winUI/component/button_text_group.ui

    ${SRC}
    res_pic.qrc
    # ${acore_src}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(CVUseServer
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET CVUseServer APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(CVUseServer SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(CVUseServer
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(CVUseServer PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt6::Core
    Qt6::Network
    ${ACore_DIR_LIB}
    # ${SPDLOG_TEST_LIB}
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.CVUseServer)
endif()
set_target_properties(CVUseServer PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS CVUseServer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(CVUseServer)
endif()
