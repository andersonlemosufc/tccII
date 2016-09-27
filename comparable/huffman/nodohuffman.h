#ifndef NODOHUFFMAN_H
#define NODOHUFFMAN_H

#include <QString>
#include "../comparable.h"
#include <iostream>

using namespace std;

class NodoHuffman : public Comparable
{
public:
    NodoHuffman();
    NodoHuffman(int value, int frequence);

private:
    int frequence;
    int value;
    NodoHuffman* right;
    NodoHuffman* left;
    int size;
    int height;

public:
    void setFrequence(int frequence);
    void setValue(int value);
    int getValue();
    int getFrequence();
    int compareTo(Comparable *other);
    void setLeft(NodoHuffman *left);
    void setRight(NodoHuffman *right);
    NodoHuffman *getLeft();
    NodoHuffman* getRight();
    QString toString();
    int getHeight();
    int getSize();
    void setHeight(int height);
    void setSize(int size);
    bool isLeaf();
    bool equals(NodoHuffman *other);

};

#endif // NODOHUFFMAN_H
