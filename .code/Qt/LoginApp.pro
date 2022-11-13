QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LoginApp
TEMPLATE = app


SOURCES += main.cpp \
    loginWindow.cpp


HEADERS  += \
    loginWindow.h


FORMS    += \
    loginWindow.ui


RESOURCES += \
    login.qrc
