QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    EntityGeneratingFunctions.cpp \
    GeneralFunctions.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    EntityClasses.h \
    EntityGeneratingFunctions.h \
    GeneralFunctions.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    TraversalMaykr-Cpp-GUI_en_CA.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    appIcon.qrc

RC_ICONS = ico/praetor_dexterity_on_btP_icon.ico
