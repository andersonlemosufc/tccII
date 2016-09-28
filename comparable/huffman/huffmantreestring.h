#ifndef NODOHUFFMANSTRING_H
#define NODOHUFFMANSTRING_H

#include "huffmantree.h"

class HuffmanTreeString : public HuffmanTree
{
public:
    HuffmanTreeString();
    HuffmanTreeString(string valor, int frequence);

private:
    string stringValue;

public:
    string getStringValue();
    void setStringValue(string stringValue);
    int compareTo(Comparable *other);
    QString toString();

};

#endif // NODOHUFFMANSTRING_H
