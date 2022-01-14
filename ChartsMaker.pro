MOC_DIR     = build/moc
OBJECTS_DIR = build/obj
UI_DIR      = build/ui
RCC_DIR     = build/

QT       += core gui charts widgets printsupport

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    charts.cpp \
    controller.cpp \
    datamatrix.cpp \
    initwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    model.cpp \
    aboutwindow.cpp \
    contactswindow.cpp \

HEADERS += \
    charts.h \
    controller.h \
    datamatrix.h \
    initwindow.h \
    mainwindow.h \
    model.h \
    aboutwindow.h \
    contactswindow.h \

RESOURCES   = application.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
