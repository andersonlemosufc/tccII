#include "nodohuffman.h"

NodoHuffman::NodoHuffman()
{
    this->left = this->right = NULL;
    this->size = 1;
    this->height = 0;
}

NodoHuffman::NodoHuffman(int value, int frequence)
{
    this->frequence = frequence;
    this->value = value;
    this->left = this->right = NULL;
    this->size = 1;
    this->height = 0;
}

void NodoHuffman::setFrequence(int frequence)
{
    this->frequence = frequence;
}

void NodoHuffman::setValue(int value)
{
    this->value = value;
}

int NodoHuffman::getValue()
{
    return this->value;
}

int NodoHuffman::getFrequence()
{
    return this->frequence;
}

int NodoHuffman::compareTo(Comparable *other)
{
    NodoHuffman *o = (NodoHuffman*) other;
    return (this->frequence - o->getFrequence());
}

void NodoHuffman::setLeft(NodoHuffman *left)
{
    this->left = left;
}

void NodoHuffman::setRight(NodoHuffman *right)
{
    this->right = right;
}

NodoHuffman *NodoHuffman::getLeft()
{
    return this->left;
}

NodoHuffman *NodoHuffman::getRight()
{
    return this->right;
}

QString NodoHuffman::toString()
{

    QString res = "";
    res.append("[valor: ").append(((char)this->value)).append(", ");
    res.append(QString("frequencia: %1").arg(this->frequence)).append(", ");
    res.append("left: ").append(this->left==NULL ? "NULO": "NAO NULO").append(", ");
    res.append("right: ").append(this->right==NULL ? "NULO": "NAO NULO").append("]");
    return res;
}

int NodoHuffman::getHeight()
{
    return this->height;
}

int NodoHuffman::getSize()
{
    return this->size;
}

void NodoHuffman::setHeight(int height)
{
    this->height = height;
}

void NodoHuffman::setSize(int size)
{
    this->size = size;
}

bool NodoHuffman::isLeaf()
{
    return (this->left==NULL && this->right==NULL);
}

bool NodoHuffman::equals(NodoHuffman *other)
{
    if(other==NULL) return false;
    if(this->isLeaf() && this->value!=other->getValue()) return false;
    if(this->left==NULL && other->getLeft()!=NULL) return false;
    if(this->left!=NULL && other->getLeft()==NULL) return false;
    if(this->right==NULL && other->getRight()!=NULL) return false;
    if(this->right!=NULL && other->getRight()==NULL) return false;
    bool aux1 = (this->left!=NULL) ? this->left->equals(other->getLeft()) : true;
    bool aux2 = (this->right!=NULL) ? this->right->equals(other->getRight()) : true;
    return (aux1 && aux2);
}

