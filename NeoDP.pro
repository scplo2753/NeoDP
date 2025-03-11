QT += core gui widgets

CONFIG += c++17

win32-msvc*:QMAKE_CXXFLAGS += /utf-8
# QMAKE_LFLAGS += "/MANIFESTUAC:\"level='requireAdministrator' uiAccess='false'\""

SOURCES += \
    $$files($$PWD/src/*.cpp) \
    $$files(src/Common/*.cpp) \
    $$files(src/DTC/*.cpp) \
    src/DTC/HARM/harmsectionmanager.cpp \
    src/DTC/HARM/jsonreader.cpp \
    src/DTC/HARM/harmlistdialog.cpp \
    src/DTC/STPT/stptsortfilterproxymodel.cpp \
    src/DTC/STPT/stptitemmodel.cpp

HEADERS += \
    $$files($$PWD/src/*.h) \
    $$files(src/Common/*.h) \
    $$files(src/DTC/*.h) \
    src/DTC/HARM/harmsectionmanager.h \
    src/DTC/HARM/jsonreader.h \
    src/DTC/HARM/harmlistdialog.h \
    src/DTC/STPT/stptsortfilterproxymodel.h \
    src/DTC/STPT/stptitemmodel.h \
    src/DTC/STPT/STPTMap.h


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
