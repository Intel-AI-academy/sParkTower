QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    car.cpp \
    charge.cpp \
    chargemanagerdialog.cpp \
    charginginfo.cpp \
    garage.cpp \
    garagemanagerdialog.cpp \
    infodatabase.cpp \
    main.cpp \
    mainui.cpp \
    managermodeui.cpp \
    managerpasswordui.cpp \
    parkinginfo.cpp \
    parkinglog.cpp \
    paymentdialog.cpp \
    paymentui.cpp \
    registerdialog.cpp \
    socketclient.cpp \
    timer.cpp \
    usermodeui.cpp

HEADERS += \
    car.h \
    charge.h \
    chargemanagerdialog.h \
    charginginfo.h \
    garage.h \
    garagemanagerdialog.h \
    infodatabase.h \
    mainui.h \
    managermodeui.h \
    managerpasswordui.h \
    parkinginfo.h \
    parkinglog.h \
    paymentdialog.h \
    paymentui.h \
    registerdialog.h \
    socketclient.h \
    timer.h \
    usermodeui.h

FORMS += \
    chargemanagerdialog.ui \
    garagemanagerdialog.ui \
    mainui.ui \
    managermodeui.ui \
    managerpasswordui.ui \
    paymentdialog.ui \
    paymentui.ui \
    registerdialog.ui \
    usermodeui.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
