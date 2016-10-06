#include "util.h"

Util::Util()
{

}

void Util::setBit(unsigned char *ch, unsigned char mask)
{
    *ch = mask | *ch;
}

bool Util::getBit(unsigned char *ch, unsigned char mask)
{
    return (*ch & mask);
}

void Util::printTable(QMap<int, TableValueHuffman> *map)
{
    QList<int>keys = map->keys();
    foreach(int k, keys){
        string valor = "";
        TableValueHuffman tv = map->value(k);
        for(int i=0,m=128;i<tv.length;i++,m>>=1){
            if(m==0) m=128;
            int index = i/8;
            unsigned char ch = (unsigned char) tv.value[index];
            valor += ((ch & m) ? "1" : "0");
        }

        cout << (char)k << ": " << valor << endl;
    }
}

void Util::printBinary(char *v, int tam)
{
    string valor = "";
    for(int k=0;k<tam;k++){
        unsigned char c = (unsigned char) v[k];
        for(int m=128;m>0;m>>=1){
            valor += ((c & m)?"1":"0");
        }
    }
    cout << "valor: " << valor << endl;
}

void Util::printBinary(unsigned char *v, int tam)
{
    string valor = "";
    for(int k=0;k<tam;k++){
        for(int m=128;m>0;m>>=1){
            valor += ((v[k] & m)?"1":"0");
        }
    }
    cout << "valor: " << valor << endl;
}

int Util::toInt(char *v, int tam)
{
    int res = 0;
    for(int k=0;k<tam;k++) res = res*10+(v[k]-'0');
    return res;
}

