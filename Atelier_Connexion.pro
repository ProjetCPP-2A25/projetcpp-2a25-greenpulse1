#-------------------------------------------------
#
# Project created by QtCreator
#
#-------------------------------------------------

QT += core gui widgets sql charts multimedia multimediawidgets axcontainer printsupport

TARGET = Atelier_Connexion
TEMPLATE = app

# Enable deprecated warnings for APIs
DEFINES += QT_DEPRECATED_WARNINGS




# Use modern C++ features
CONFIG += c++11

# Source files
SOURCES += \
    complaints.cpp \
    main.cpp \
    mainwindow.cpp \
    connection.cpp

# Header files
HEADERS += \
    complaints.h \
    mainwindow.h \
    connection.h

# UI forms
FORMS += \
    mainwindow.ui

# Deployment settings
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    i1.png

RESOURCES += \
    background.qrc \
    p.qrc
