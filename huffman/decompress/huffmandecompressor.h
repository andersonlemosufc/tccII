#ifndef HUFFMANDECOMPRESSOR_H
#define HUFFMANDECOMPRESSOR_H

#include <QFile>
#include <fstream>
#include "./comparable/huffman/huffmantree.h"
#include "./util/constants.h"
#include "./util/util.h"


class HuffmanDecompressor
{
public:
    HuffmanDecompressor();
    void decompress(string filename);

    HuffmanTree* lastTreeTest;

private:
    void resetBuffer();

    char* buffer;
    int bufferLength;
};

#endif // HUFFMANDECOMPRESSOR_H
