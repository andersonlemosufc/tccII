#ifndef UTIL_H
#define UTIL_H

#include <math.h>
#include "./huffman/compress/huffmancompressor.h"

class Util
{
public:
    Util();
    static void setBit(unsigned char *ch, unsigned char mask);
    static bool getBit(unsigned char *ch, unsigned char mask);
    static void printTable(QMap<int,TableValueHuffman>* map);
    static void printBinary(unsigned char *v, int tam);
    static void printBinary(char *v, int tam);
    static int toInt(char *v, int tam);

};

#endif // UTIL_H
