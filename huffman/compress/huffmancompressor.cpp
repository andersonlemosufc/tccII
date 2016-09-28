#include "huffmancompressor.h"

HuffmanCompressor::HuffmanCompressor()
{

}

void HuffmanCompressor::compress(QString filename)
{
    int *map = this->createMap(filename);

    HuffmanTree* tree = this->createTree(map);
    QMap<int,TableValueHuffman>* table = tree->toDictionary();
    this->write(table, filename, tree);
}

int *HuffmanCompressor::createMap(QString filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)) return NULL;

    int* map = new int[256];
    for(int k=0;k<256;k++){
        map[k] = 0;
    }
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.read(CAPACITY_BUFFER);
        string l = line.toStdString();
        const char *data = l.c_str();
        for(int k=0,t=l.length();k<t;k++){
            unsigned char c = (unsigned char) data[k];
            int index = (int) c;
            map[index]++;
        }
    }
    return map;
}

HuffmanTree *HuffmanCompressor::createTree(int *map)
{
    PriorityQueue *fila = new PriorityQueue();
    for(int k=0;k<256;k++){
        if(map[k]>0){
            HuffmanTree* value = new HuffmanTree(k, map[k]);
            fila->insert(value);
        }
    }
    return this->createTree(fila);
}

HuffmanTree *HuffmanCompressor::createTree(PriorityQueue *queue)
{
    int n = queue->getSize();
    for(int k=0;k<(n-1);k++){
        HuffmanTree* x = (HuffmanTree*)queue->removeMin();
        HuffmanTree* y = (HuffmanTree*)queue->removeMin();
        HuffmanTree* z = new HuffmanTree(0, x->getFrequence()+y->getFrequence());
        z->setLeft(x);
        z->setRight(y);
        queue->insert(z);

    }
    return (HuffmanTree*)queue->removeMin();
}



void HuffmanCompressor::write(QMap<int, TableValueHuffman> *mapa, QString filename, HuffmanTree *tree)
{
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)) return;

    QFile saida(filename+".huff");
    if(!saida.open(QIODevice::WriteOnly)) return;

    QTextStream in(&file);
    QTextStream out(&saida);

    out << " ";
    int len = tree->getNumberOfLeafs()+ceil(tree->getSize()/8.0);
    out << len;
    out << "\n";
    out << (const char*) tree->toBinary();
    out.flush();
    this->resetBuffer();

    unsigned char mask = 128, ch=0;
    while(!in.atEnd()){
        string line = in.read(CAPACITY_BUFFER).toStdString();
        const char *data = line.c_str();
        for(int k=0,t=line.length();k<t;k++){
            unsigned char c = (unsigned char) data[k];
            TableValueHuffman tv = mapa->value(c);
            for(int i=0,m=128,index=0;i<tv.length;i++){
                if(m & tv.value[index]){
                    ch = ch | mask;
                }
                m>>=1;
                if(m==0){
                    m=128;
                    index++;
                }
                mask>>=1;
                if(mask==0){
                    mask = 128;
                    this->buffer[this->bufferLength++] = ch;
                    ch = 0;
                    if(this->bufferLength==CAPACITY_BUFFER){
                        out << (const char*) this->buffer;
                        out.flush();
                        this->resetBuffer();
                    }
                }
            }
        }
    }
    unsigned char* aux = new unsigned char[this->bufferLength];
    for(int k=0;k<this->bufferLength;k++){
        aux[k] = this->buffer[k];
    }
    out << (const char*) aux;
    out.seek(0);
    int tam = 0;
    while(mask>0) {
        tam++;
        mask>>=1;
    }
    out << tam;
    out.flush();
}



void HuffmanCompressor::resetBuffer()
{
    int tam = CAPACITY_BUFFER;
    this->buffer = new unsigned char[tam];
    this->bufferLength = 0;
}

