#ifndef NODOHUFFMANSTRING_H
#define NODOHUFFMANSTRING_H

#include "nodohuffman.h"

class NodoHuffmanString : public NodoHuffman
{
public:
    NodoHuffmanString();
    NodoHuffmanString(string valor, int frequence);

private:
    string stringValue;

public:
    string getStringValue();
    void setStringValue(string stringValue);
    int compareTo(Comparable *other);
    QString toString();

};

#endif // NODOHUFFMANSTRING_H
