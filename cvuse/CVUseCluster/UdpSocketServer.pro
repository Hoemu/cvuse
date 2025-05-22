QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
TARGET += CVUseCluster

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Server\config_setting.cpp \
    main.cpp \
    UI\mainwindow.cpp \
    Server\remote_udp.cpp \
    Server\remote_tcp.cpp

HEADERS += \
    Server\config_setting.h \
    UI\mainwindow.h \
    Server\remote_udp.h \
    Server\remote_tcp.h \

FORMS += \
    UI\mainwindow.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


# ui 上的端口号不一致导致

DISTFILES += \
    UI\server \
    UiHeader

