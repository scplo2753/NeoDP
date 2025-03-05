QT += core gui widgets

CONFIG += c++17

win32-msvc*:QMAKE_CXXFLAGS += /utf-8
# QMAKE_LFLAGS += "/MANIFESTUAC:\"level='requireAdministrator' uiAccess='false'\""

SOURCES += \
    $$files($$PWD/src/*.cpp) \
    $$files(src/Common/*.cpp) \
    $$files(src/DTC/*.cpp) \
    src/DTC/harmsectionmanager.cpp \
    src/DTC/jsonreader.cpp \
    src/DTC/harmlistdialog.cpp \
    src/DTC/stptsortfilterproxymodel.cpp

HEADERS += \
    $$files($$PWD/src/*.h) \
    $$files(src/Common/*.h) \
    $$files(src/DTC/*.h) \
    src/DTC/STPTMap.h \
    src/DTC/harmsectionmanager.h \
    src/DTC/jsonreader.h \
    src/DTC/harmlistdialog.h \
    src/DTC/stptsortfilterproxymodel.h


FORMS += $$PWD/src/NeoDP.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Resource/4.37.6/DTCInfo.json \
    src/4_37_6_Default.ini \
    src/Actions

RESOURCES += \
    res.qrc
