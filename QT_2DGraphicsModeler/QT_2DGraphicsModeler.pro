QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ellipse.cpp \
    line.cpp \
    logindialog.cpp \
    main.cpp \
    mainwindow.cpp \
    moveshape.cpp \
    polygon.cpp \
    polyline.cpp \
    rectangle.cpp \
    renderarea.cpp \
    shape.cpp \
    testimonial.cpp \
    text.cpp \
    textparser.cpp \
    contactus.cpp

HEADERS += \
    ellipse.h \
    line.h \
    logindialog.h \
    mainwindow.h \
    moveshape.h \
    polygon.h \
    polyline.h \
    rectangle.h \
    renderarea.h \
    serializer.h \
    shape.h \
    testimonial.h \
    text.h \
    textparser.h \
    vector.h \
    contactus.h

FORMS += \
    logindialog.ui \
    mainwindow.ui \
    contactus.ui \
    moveshape.ui \
    testimonial.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    shape_input_file_specs.txt \
    shapes.txt \
    testimonial.txt

RESOURCES += \
    logo.qrc
