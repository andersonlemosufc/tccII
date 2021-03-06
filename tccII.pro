#-------------------------------------------------
#
# Project created by QtCreator 2016-09-27T17:51:59
#
#-------------------------------------------------

QT       += core gui xml xmlpatterns

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tccII
TEMPLATE = app

CONFIG += c++14

SOURCES += main.cpp\
        mainwindow.cpp \
    queue/priorityqueue.cpp \
    comparable/comparable.cpp \
    huffman/compress/huffmancompressor.cpp \
    huffman/decompress/huffmandecompressor.cpp \
    xmlparser/streamparser.cpp \
    comparable/huffman/huffmantree.cpp \
    comparable/huffman/huffmantreestring.cpp \
    util/util.cpp \
    xmlparser/svgvalidator.cpp

HEADERS  += mainwindow.h \
    queue/priorityqueue.h \
    comparable/comparable.h \
    huffman/compress/huffmancompressor.h \
    huffman/decompress/huffmandecompressor.h \
    xmlparser/streamparser.h \
    comparable/huffman/huffmantree.h \
    comparable/huffman/huffmantreestring.h \
    util/constants.h \
    util/util.h \
    xmlparser/svgvalidator.h \
    tree/patricia.h

FORMS    += mainwindow.ui
