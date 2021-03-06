﻿#ifndef NODOHUFFMAN_H
#define NODOHUFFMAN_H

#include <QString>
#include <QDebug>
#include <QMap>
#include <iostream>
#include <math.h>
#include "../comparable.h"

using namespace std;

typedef struct {
    string value;
    int length;
} TableValueHuffman;

class HuffmanTree : public Comparable
{
public:
    HuffmanTree();
    HuffmanTree(int value, int frequence);

private:
    int frequence;
    int value;
    HuffmanTree* right;
    HuffmanTree* left;
    int size;
    int height;
    int numberOfLeafs;

public:
    void setFrequence(int frequence);
    void setValue(int value);
    int getValue();
    int getFrequence();
    int compareTo(Comparable *other);
    void setLeft(HuffmanTree *left);
    void setRight(HuffmanTree *right);
    HuffmanTree *getLeft();
    HuffmanTree* getRight();
    QString toString();
    int getHeight();
    int getSize();
    bool isLeaf();
    bool equals(HuffmanTree *other);
    void print();
    int getNumberOfLeafs();
    QMap<int,TableValueHuffman>* toDictionary();
    unsigned char* toBinary();
    /*static HuffmanTree* buildTree(QChar *structure);
    static HuffmanTree* buildTree(char *structure, int tam);*/
    static HuffmanTree* buildTree(char *structure);

private:
    void updateVariables();
    void print(HuffmanTree *nodo, int t);
    void toDictionary(HuffmanTree* nodo, QMap<int, TableValueHuffman> *mapa, TableValueHuffman *aux, unsigned char *mask, int nivel);
    void toBinary(HuffmanTree* nodo, unsigned char* vector, unsigned char *mask, int *index);
    /*static HuffmanTree* buildTree(QChar *structure, int* index, unsigned char* mask);*/
    static HuffmanTree* buildTree(char *structure, int* index, unsigned char* mask);

};

#endif // NODOHUFFMAN_H
