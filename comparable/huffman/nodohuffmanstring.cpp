#include "nodohuffmanstring.h"

NodoHuffmanString::NodoHuffmanString() :
    NodoHuffman()
{
    this->setStringValue(NULL);
}

NodoHuffmanString::NodoHuffmanString(string valor, int frequence) :
    NodoHuffman(NULL, frequence)
{
    this->stringValue = valor;
}

string NodoHuffmanString::getStringValue()
{
    return this->stringValue;
}

void NodoHuffmanString::setStringValue(string stringValue)
{
    this->stringValue = stringValue;
}

int NodoHuffmanString::compareTo(Comparable *other)
{
    NodoHuffmanString *o = (NodoHuffmanString*) other;
    return (this->getFrequence() - o->getFrequence());
}

QString NodoHuffmanString::toString()
{
    QString res = "";
    res.append("[valor: ").append(QString::fromStdString(this->stringValue)).append(", ");
    res.append("frequencia: ").append(QString(this->getFrequence())).append(", ");
    res.append("left: ").append(this->getLeft()==NULL ? "NULO": "NAO NULO").append(", ");
    res.append("right: ").append(this->getRight()==NULL ? "NULO": "NAO NULO").append("]");
    return res;
}

