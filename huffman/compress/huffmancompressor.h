#ifndef HUFFMANCOMPRESSOR_H
#define HUFFMANCOMPRESSOR_H

#include <QFile>
#include <QMap>
#include <fstream>
#include "./comparable/huffman/huffmantree.h"
#include "./queue/priorityqueue.h"
#include "./util/constants.h"
#include "./util/util.h"

class HuffmanCompressor
{
public:
    HuffmanCompressor();
    void compress(string filename);

    HuffmanTree *lastTreeTest;

private:
    int* createMap(string filename);
    HuffmanTree* createTree(int *map);
    HuffmanTree* createTree(PriorityQueue* queue);
    void write(QMap<int,TableValueHuffman>*mapa, string filename, HuffmanTree *tree);
    void resetBuffer();


    unsigned char* buffer;
    int bufferLength;
};


#endif // HUFFMANCOMPRESSOR_H
