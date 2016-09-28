#ifndef HUFFMANDECOMPRESSOR_H
#define HUFFMANDECOMPRESSOR_H

#include <QFile>
#include <fstream>
#include "./comparable/huffman/huffmantree.h"
#include "./util/constants.h"


class HuffmanDecompressor
{
public:
    HuffmanDecompressor();
    void decompress(QString filename);

private:
    void resetBuffer();

    char* buffer;
    int bufferLength;
};

#endif // HUFFMANDECOMPRESSOR_H
