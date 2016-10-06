#include "huffmantree.h"

HuffmanTree::HuffmanTree()
{
    this->left = this->right = NULL;
    this->value = this->frequence = 0;
    this->size = 1;
    this->height = 0;
    this->numberOfLeafs = 1;
}

HuffmanTree::HuffmanTree(int value, int frequence)
{
    this->frequence = frequence;
    this->value = value;
    this->left = this->right = NULL;
    this->size = 1;
    this->height = 0;
    this->numberOfLeafs = 1;
}

void HuffmanTree::setFrequence(int frequence)
{
    this->frequence = frequence;
}

void HuffmanTree::setValue(int value)
{
    this->value = value;
}

int HuffmanTree::getValue()
{
    return this->value;
}

int HuffmanTree::getFrequence()
{
    return this->frequence;
}

int HuffmanTree::compareTo(Comparable *other)
{
    HuffmanTree *o = (HuffmanTree*) other;
    return (this->frequence - o->getFrequence());
}

void HuffmanTree::setLeft(HuffmanTree *left)
{
    this->left = left;
    this->updateVariables();
}

void HuffmanTree::setRight(HuffmanTree *right)
{
    this->right = right;
    this->updateVariables();
}

HuffmanTree *HuffmanTree::getLeft()
{
    return this->left;
}

HuffmanTree *HuffmanTree::getRight()
{
    return this->right;
}

QString HuffmanTree::toString()
{

    QString res = "";
    res.append("[valor: ").append(((char)this->value)).append(", ");
    res.append(QString("frequencia: %1").arg(this->frequence)).append(", ");
    res.append("left: ").append(this->left==NULL ? "NULO": "NAO NULO").append(", ");
    res.append("right: ").append(this->right==NULL ? "NULO": "NAO NULO").append("]");
    return res;
}

int HuffmanTree::getHeight()
{
    return this->height;
}

int HuffmanTree::getSize()
{
    return this->size;
}

bool HuffmanTree::isLeaf()
{
    return (this->left==NULL && this->right==NULL);
}

bool HuffmanTree::equals(HuffmanTree *other)
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

void HuffmanTree::print()
{
    this->print(this, 0);
}

int HuffmanTree::getNumberOfLeafs()
{
    return this->numberOfLeafs;
}


QMap<int, TableValueHuffman> *HuffmanTree::toDictionary()
{
    QMap<int, TableValueHuffman>* mapa = new QMap<int, TableValueHuffman>();
    int tam = ceil(this->height/8.0);
    char *c = new char[tam];
    for(int k=0;k<tam;k++) c[k] = 0;
    TableValueHuffman tv = {string(c, tam), 0};
    unsigned char mask = 0;
    this->toDictionary(this,mapa,&tv,&mask,0);
    return mapa;
}

unsigned char *HuffmanTree::toBinary()
{
    int tam = this->numberOfLeafs+ceil(this->size/8.0);
    unsigned char* res = new unsigned char[tam];
    for(int k=0;k<tam;k++){
        res[k] = 0;
    }
    unsigned char mask = 128;
    int index = 0;
    this->toBinary(this,res,&mask,&index);
    return res;
}
/*
HuffmanTree *HuffmanTree::buildTree(QChar *structure)
{
    int index = -1;
    unsigned char mask = 0;
    return HuffmanTree::buildTree(structure,&index,&mask);
}

HuffmanTree *HuffmanTree::buildTree(char *structure, int tam)
{
    QChar *ch = new QChar[tam];
    for(int k=0;k<tam;k++){
        ch[k] = QChar(structure[k]);
    }
    return HuffmanTree::buildTree(ch);
}*/

HuffmanTree *HuffmanTree::buildTree(char *structure)
{
    int index = -1;
    unsigned char mask = 0;
    return HuffmanTree::buildTree(structure,&index,&mask);
}

void HuffmanTree::updateVariables()
{
    int sl=0, sr=0, hl=0, hr=0, ht=0, ll=0, lr=0;
    if(this->right!=NULL){
        lr = this->right->getNumberOfLeafs();
        sr = this->right->getSize();
        hr = this->right->getHeight();
        ht=1;
    }
    if(this->left!=NULL){
        ll = this->left->getNumberOfLeafs();
        sl = this->left->getSize();
        hl = this->left->getHeight();
        ht=1;
    }
    this->numberOfLeafs = (this->isLeaf()) ? 1 : ll+lr;
    this->size = sl+sr+1;
    this->height = max(hl,hr)+ht;
}


//CHAMADAS RECURSIVAS

void HuffmanTree::print(HuffmanTree *nodo, int t)
{
    if(nodo!=NULL){
        QString s = QString("%1").arg(t);
        for(int k=0;k<t;k++)s+="    ";
        s = QString(s.append("val: ").append((QChar)nodo->getValue()).append(" > freq: %1")).arg(nodo->getFrequence());
        qDebug() << s;
        this->print(nodo->getLeft(), t+1);
        this->print(nodo->getRight(), t+1);
    }
}

void HuffmanTree::toDictionary(HuffmanTree *nodo, QMap<int, TableValueHuffman> *mapa, TableValueHuffman *aux, unsigned char *mask, int nivel)
{
    (*mask)>>=1;
    if((*mask)==0){
        (*mask) = 128;
    }
    if(nodo->isLeaf()){
        aux->length = nivel;
        mapa->insert(nodo->getValue(), *aux);
    } else {
        int index = nivel/8;

        aux->value[index] = (aux->value[index] & ~(*mask));
        this->toDictionary(nodo->getLeft(), mapa, aux, mask, nivel+1);
        (*mask)<<=1;
        if((*mask)==0){
            (*mask) = 1;
        }

        aux->value[index] = (aux->value[index] | *mask);
        this->toDictionary(nodo->getRight(), mapa, aux, mask, nivel+1);
        (*mask)<<=1;
        if((*mask)==0){
            (*mask) = 1;
        }
    }
}

void HuffmanTree::toBinary(HuffmanTree *nodo, unsigned char *vector, unsigned char *mask, int *index)
{
    if((*mask)==0){
        (*mask) = 128;
        (*index)++;
    }
    if(nodo->isLeaf()){
        vector[(*index)] = vector[(*index)] | (*mask);
        for(int k=128;k>0;k>>=1){
            (*mask)>>=1;
            if((*mask)==0){
                (*mask) = 128;
                (*index)++;
            }
            if(k & nodo->getValue())
                vector[(*index)] = vector[(*index)] | (*mask);
        }
        (*mask)>>=1;
    } else {
        (*mask)>>=1;
        this->toBinary(nodo->getLeft(),vector,mask,index);
        this->toBinary(nodo->getRight(),vector,mask,index);
    }
}

HuffmanTree *HuffmanTree::buildTree(char *structure, int *index, unsigned char *mask)
{
    HuffmanTree* nodo = new HuffmanTree();
    (*mask)>>=1;
    if((*mask)==0){
        (*mask)=128;
        (*index)++;
    }
    unsigned char ch = (unsigned char) structure[(*index)];
    if((*mask) & ch){
        unsigned char v = 0;
        for(int m=128;m>0;m>>=1){
            (*mask)>>=1;
            if((*mask)==0){
                (*mask)=128;
                (*index)++;
                ch = structure[(*index)];
            }
            if((*mask) & ch) v = v | m;
        }
        nodo->setValue(v);
    } else {
        nodo->setLeft(HuffmanTree::buildTree(structure, index, mask));
        nodo->setRight(HuffmanTree::buildTree(structure, index, mask));
    }
    return nodo;
}

/*HuffmanTree *HuffmanTree::buildTree(QChar *structure, int *index, unsigned char *mask)
{
    HuffmanTree* nodo = new HuffmanTree();
    (*mask)>>=1;
    if((*mask)==0){
        (*mask)=128;
        (*index)++;
    }
    unsigned char ch = (unsigned char) structure[(*index)].cell();
    if((*mask) & ch){
        unsigned char v = 0;
        for(int m=128;m>0;m>>=1){
            (*mask)>>=1;
            if((*mask)==0){
                (*mask)=128;
                (*index)++;
                ch = structure[(*index)].cell();
            }
            if((*mask) & ch) v = v | m;
        }
        nodo->setValue(v);
    } else {
        nodo->setLeft(HuffmanTree::buildTree(structure, index, mask));
        nodo->setRight(HuffmanTree::buildTree(structure, index, mask));
    }
    return nodo;
}
*/
