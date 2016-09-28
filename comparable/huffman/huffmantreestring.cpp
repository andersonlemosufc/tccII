#include "huffmantreestring.h"

HuffmanTreeString::HuffmanTreeString() :
    HuffmanTree()
{
    this->setStringValue(NULL);
}

HuffmanTreeString::HuffmanTreeString(string valor, int frequence) :
    HuffmanTree(0, frequence)
{
    this->stringValue = valor;
}

string HuffmanTreeString::getStringValue()
{
    return this->stringValue;
}

void HuffmanTreeString::setStringValue(string stringValue)
{
    this->stringValue = stringValue;
}

int HuffmanTreeString::compareTo(Comparable *other)
{
    HuffmanTreeString *o = (HuffmanTreeString*) other;
    return (this->getFrequence() - o->getFrequence());
}

QString HuffmanTreeString::toString()
{
    QString res = "";
    res.append("[valor: ").append(QString::fromStdString(this->stringValue)).append(", ");
    res.append("frequencia: ").append(QString(this->getFrequence())).append(", ");
    res.append("left: ").append(this->getLeft()==NULL ? "NULO": "NAO NULO").append(", ");
    res.append("right: ").append(this->getRight()==NULL ? "NULO": "NAO NULO").append("]");
    return res;
}

