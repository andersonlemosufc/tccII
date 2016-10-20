#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{



    Patricia<int>* patricia = new Patricia<int>();

    string s = "sre";
    string d = "safsdas";
    string c = "sbf";
    string f = "srs";

    string px = "safs";
patricia->insert(s, 33);
patricia->insert(d, 14);
patricia->insert(c, -53);
patricia->insert(f, 64);

    string a = patricia->largerPrefix(px);
    cout << "tamanho: " << patricia->getSize() << endl;

    patricia->
    cout << a << endl;









    return 0;
    string f0 = "/home/anderson/Documentos/tmp/aux.txt";
    string f1 = "/home/anderson/Documentos/tmp/books.xml";
    string f2 = "/home/anderson/Documentos/tmp/brasil.svg.aux";
    string f3 = "/home/anderson/Documentos/tmp/a.txt";
    string f4 = "/home/anderson/Documentos/tmp/star.csv";
    string f5 = "/home/anderson/Documentos/tmp/sample.xml";


    string filename = f5;
    HuffmanCompressor* comp = new HuffmanCompressor();
    HuffmanDecompressor *dec = new HuffmanDecompressor();

    clock_t t0, tf;
    double tC, tD;

    qDebug() << "iniciando compressão...";
    t0 = clock();
    comp->compress(filename);
    tf = clock();
    tC = ( (double) (tf - t0) ) / CLOCKS_PER_SEC;
    qDebug() << "fim da compressão.";

    qDebug() << "iniciando descompressão...";
    t0 = clock();
    dec->decompress(filename+".huff");
    tf = clock();
    tD = ( (double) (tf - t0) ) / CLOCKS_PER_SEC;
    qDebug() << "fim da descompressão.";

    printf("Tempo de compressao: %lf s\n", tC);
    printf("Tempo de descompressao: %lf s\n", tD);





    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    //return a.exec();

    return 0;
}
