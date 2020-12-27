TEMPLATE = app
TARGET = Entry
QT += core gui widgets

SOURCES += ../src/*.cpp
HEADERS += ../src/*.h
HEADERS += ../include/*.h

CONFIG += c++17 -lfilesystem link_pkgconfig
PKGCONFIG += libqalculate
