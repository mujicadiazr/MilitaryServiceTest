#-------------------------------------------------
#
# Project created by QtCreator 2014-06-11T23:33:56
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = MilitaryServiceTest
TEMPLATE = app


SOURCES += main.cpp \
    view/militaryservicetestview.cpp \
    bussines/icomparable.cpp \
    bussines/cfeature.cpp \
    bussines/cobject.cpp \
    bussines/cknowledgedb.cpp \
    bussines/cpatternrecongnition.cpp \
    bussines/CFeatures/cfeature1.cpp \
    bussines/CFeatures/cfeature2.cpp \
    bussines/CFeatures/cfeature3.cpp \
    bussines/CFeatures/cfeature4.cpp \
    bussines/CFeatures/cfeature5.cpp \
    bussines/CFeatures/cfeature6.cpp \
    bussines/CFeatures/cfeature7.cpp \
    bussines/CFeatures/cfeature8.cpp \
    bussines/CFeatures/cfeature9.cpp \
    bussines/CFeatures/cfeature10.cpp \
    bussines/CFeatures/cfeature11.cpp \
    bussines/CFeatures/cfeature12.cpp \
    bussines/CFeatures/cfeature13.cpp \
    bussines/CFeatures/cfeature14.cpp \
    bussines/CFeatures/cfeature15.cpp \
    common/cfactoryfeature.cpp \
    view/fknowledgebase.cpp \
    common/cmodelknowledgebase.cpp

HEADERS  += \
    view/militaryservicetestview.h \
    bussines/icomparable.h \
    common/enums.h \
    bussines/cfeature.h \
    bussines/cobject.h \
    bussines/cknowledgedb.h \
    bussines/cpatternrecongnition.h \
    bussines/CFeatures/cfeature1.h \
    bussines/CFeatures/cfeature2.h \
    bussines/CFeatures/cfeature3.h \
    bussines/CFeatures/cfeature4.h \
    bussines/CFeatures/cfeature5.h \
    bussines/CFeatures/cfeature6.h \
    bussines/CFeatures/cfeature7.h \
    bussines/CFeatures/cfeature8.h \
    bussines/CFeatures/cfeature9.h \
    bussines/CFeatures/cfeature10.h \
    bussines/CFeatures/cfeature11.h \
    bussines/CFeatures/cfeature12.h \
    bussines/CFeatures/cfeature13.h \
    bussines/CFeatures/cfeature14.h \
    bussines/CFeatures/cfeature15.h \
    common/cfactoryfeature.h \
    view/fknowledgebase.h \
    common/cmodelknowledgebase.h

FORMS    += \
    view/militaryservicetestview.ui \
    view/fknowledgebase.ui
