#include "huffmandecompressor.h"

HuffmanDecompressor::HuffmanDecompressor()
{

}

void HuffmanDecompressor::decompress(QString filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)) return;

    QTextStream in(&file);
    ofstream out((filename+".dhf").toStdString().c_str());

    int bitsDespisedContent = in.read(1).toInt();
    int tamTree = in.readLine().toInt();
    QString s = in.read(tamTree);
    QChar *data = s.data();
    HuffmanTree *tree = HuffmanTree::buildTree(data);
    HuffmanTree *nodo = tree;
    bool flag = true;
    this->resetBuffer();
    while(!in.atEnd() && flag){
        QString line = in.read(CAPACITY_BUFFER);
        QChar *data = line.data();
        int t = line.length();
        if(in.atEnd()) t--;
        for(int k=0;k<t && flag;k++){
            unsigned char ch = (unsigned char) data[k].cell();
            for(int i=0,m=128;i<8;i++,m>>=1){
                if(in.atEnd() && k==(t-1) && i>=(8-bitsDespisedContent)){
                    flag = false;
                    break;
                }
                nodo = (ch & m) ? nodo->getRight() : nodo->getLeft();
                if(nodo->isLeaf()){
                    this->buffer[this->bufferLength++] = (char) nodo->getValue();
                    nodo = tree;
                    if(this->bufferLength==CAPACITY_BUFFER){
                        out << this->buffer;
                        out.flush();
                        this->resetBuffer();
                    }
                }
            }
        }
    }

    if(this->bufferLength>0){
        char* resto = new char[this->bufferLength];
        for(int k=0;k<this->bufferLength;k++){
            resto[k] = this->buffer[k];
        }
        out << resto;
        out.flush();
    }

}

void HuffmanDecompressor::resetBuffer()
{
    this->buffer = new char[CAPACITY_BUFFER];
    this->bufferLength = 0;
}

