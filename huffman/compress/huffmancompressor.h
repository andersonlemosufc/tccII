#ifndef HUFFMANCOMPRESSOR_H
#define HUFFMANCOMPRESSOR_H

#include <QFile>
#include <QMap>
#include "./comparable/huffman/huffmantree.h"
#include "./queue/priorityqueue.h"
#include "./util/constants.h"

class HuffmanCompressor
{
public:
    HuffmanCompressor();
    void compress(QString filename);



private:
    int* createMap(QString filename);
    HuffmanTree* createTree(int *map);
    HuffmanTree* createTree(PriorityQueue* queue);
    void write(QMap<int,TableValueHuffman>*mapa, QString filename, HuffmanTree *tree);
    void resetBuffer();


    unsigned char* buffer;
    int bufferLength;
};


#endif // HUFFMANCOMPRESSOR_H
