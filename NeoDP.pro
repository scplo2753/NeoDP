QT += core gui widgets

CONFIG += c++17

win32-msvc*:QMAKE_CXXFLAGS += /utf-8
# QMAKE_LFLAGS += "/MANIFESTUAC:\"level='requireAdministrator' uiAccess='false'\""

SOURCES += \
    $$files($$PWD/src/*.cpp) \
    src/dtc.cpp

HEADERS += \
    $$files($$PWD/src/*.h) \
    src/dtc.h

FORMS += $$PWD/src/NeoDP.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    src/4_37_6_Default.ini \
    src/Actions

RESOURCES += \
    res.qrc
