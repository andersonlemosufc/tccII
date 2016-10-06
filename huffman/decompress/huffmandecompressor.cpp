#include "huffmandecompressor.h"

HuffmanDecompressor::HuffmanDecompressor()
{

}

void HuffmanDecompressor::decompress(string filename)
{
    /*QFile file(filename);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;
    QTextStream in(&file);*/

    ifstream in(filename.data(), ifstream::binary);
    ofstream out((filename+".dhf").data());

    /*int bitsDespisedContent = in.read(1).toInt();
    int tamTree = in.readLine().toInt();
    QString s = in.read(tamTree);
    QChar *data = s.data();
    HuffmanTree *tree = HuffmanTree::buildTree(data);
    */
    char *aux = new  char[4];
    in.read(aux, 1);
    int bitsDespisedContent = aux[0]-'0';
    in.getline(aux, 4);
    int tamTree = Util::toInt(aux, in.gcount()-1);
    aux = new char[tamTree];
    in.read(aux,tamTree);
    HuffmanTree *tree = HuffmanTree::buildTree(aux);
    HuffmanTree *nodo = tree;
    bool flag = true;
    this->resetBuffer();
    /*while(!in.atEnd() && flag){
        QString line = in.read(CAPACITY_BUFFER);
        QChar *data = line.data();
        int t = line.length();*/
    char *data = new char[CAPACITY_BUFFER];
    while(!in.eof() && flag){
        in.read(data,CAPACITY_BUFFER);
        int t = in.gcount();
        for(int k=0;k<t && flag;k++){
            //unsigned char ch = (unsigned char) data[k].cell();
            unsigned char ch = (unsigned char) data[k];
            for(int i=0,m=128;i<8;i++,m>>=1){
                if(in.eof() && k==(t-1) && i>=(8-bitsDespisedContent)){
                    flag = false;
                    break;
                }
                nodo = (ch & m) ? nodo->getRight() : nodo->getLeft();
                if(nodo->isLeaf()){
                    this->buffer[this->bufferLength++] = (char) nodo->getValue();
                    nodo = tree;
                    if(this->bufferLength==CAPACITY_BUFFER){
                        out.write(this->buffer, CAPACITY_BUFFER);
                        this->bufferLength = 0;
                    }
                }
            }
        }
    }
    if(this->bufferLength>0){

        out.write(this->buffer, this->bufferLength);
        out.flush();
    }
    out.close();
    in.close();

    this->lastTreeTest = tree;
}

void HuffmanDecompressor::resetBuffer()
{
    this->buffer = new char[CAPACITY_BUFFER];
    this->bufferLength = 0;
}

