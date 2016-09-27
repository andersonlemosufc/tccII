#-------------------------------------------------
#
# Project created by QtCreator 2016-09-27T17:51:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tccII
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    queue/priorityqueue.cpp \
    comparable/huffman/nodohuffman.cpp \
    comparable/huffman/nodohuffmanstring.cpp \
    comparable/comparable.cpp \
    huffman/compress/huffmancompressor.cpp \
    huffman/decompress/huffmandecompressor.cpp

HEADERS  += mainwindow.h \
    queue/priorityqueue.h \
    comparable/huffman/nodohuffman.h \
    comparable/huffman/nodohuffmanstring.h \
    comparable/comparable.h \
    huffman/compress/huffmancompressor.h \
    huffman/decompress/huffmandecompressor.h

FORMS    += mainwindow.ui
