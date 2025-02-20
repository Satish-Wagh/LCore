OBJECTS_DIR=../output/objdir/$$basename(_PRO_FILE_PWD_)
MOC_DIR=../output/mocdir/$$basename(_PRO_FILE_PWD_)
OBJMOC=../output/objmoc/$$basename(_PRO_FILE_PWD_)
OTHER_FILES=../output/others/$$basename(_PRO_FILE_PWD_)
OUT_PWD=../output/outpwd/$$basename(_PRO_FILE_PWD_)
UI_DIR=../output/uidir/$$basename(_PRO_FILE_PWD_)
UI_HEADERS_DIR=../output/uiheaddir/$$basename(_PRO_FILE_PWD_)
UI_SOURCES_DIR=../output/uisrcdir/$$basename(_PRO_FILE_PWD_)
#-------------------------------------------------
#
# Project created by QtCreator 2012-07-06T14:41:39
#
#-------------------------------------------------

QT       += core network gui sql

#QT       -= gui

TARGET=../output/lib/LCore
CONFIG   += console
CONFIG   -= app_bundle
QMAKE_CXXFLAGS = -std=c++11
#TEMPLATE = app
TEMPLATE = lib

SOURCES += main.cpp \
    lcore.cpp \
    ftp.cpp \
    http.cpp \
    qballoontip.cpp \
    customfiledialog.cpp \
    Localcredentialdialog.cpp \
    leforpassword.cpp \
    qtjson.cpp \
    aesencryptionlib.cpp

HEADERS += \
    lcore.h \
    defineslcore.h \
    ftp.h \
    http.h \
    qballoontip.h \
    ChangeLoglcore.h \
    customfiledialog.h \
    Localcredentialdialog.h \
    leforpassword.h \
    qtjson.h \
    aesencryptionlib.h

TRANSLATIONS += LCore.ts

FORMS += \
    customfiledialog.ui \
    Localcredentialdialog.ui

LIBS += -lldap -lmcrypt -ludev  -lcurl

DEFINES += LDAP_DEPRECATED
