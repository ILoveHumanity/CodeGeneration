QT = core

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Unit/src/abstract/AbstractClassUnit.cpp \
        Unit/src/abstract/AbstractMethodUnit.cpp \
        Unit/src/abstract/AbstractPrintOperatorUnit.cpp \
        Unit/src/cpp/cppClassUnit.cpp \
        Unit/src/cpp/cppMethodUnit.cpp \
        Unit/src/cpp/cppPrintOperatorUnit.cpp \
        Unit/src/cpp/cppUnitFactory.cpp \
        Unit/src/unit.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Unit/AbstractUnitFactory.h \
    Unit/src/abstract/AbstractClassUnit.h \
    Unit/src/abstract/AbstractMethodUnit.h \
    Unit/src/abstract/AbstractPrintOperatorUnit.h \
    Unit/src/cpp/cppClassUnit.h \
    Unit/src/cpp/cppMethodUnit.h \
    Unit/src/cpp/cppPrintOperatorUnit.h \
    Unit/src/cpp/cppUnitFactory.h \
    Unit/unit.h

INCLUDEPATH += \
        Unit/src/ \
        Unit/src/abstract \
        Unit/src/cpp/ \
        Unit/src/csh/ \
        Unit/src/java/ \
        Unit/
