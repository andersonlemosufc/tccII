#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    string f0 = "/home/anderson/Documentos/tmp/aux.txt";
    string f1 = "/home/anderson/Documentos/tmp/books.xml";
    string f2 = "/home/anderson/Documentos/tmp/brasil.svg.aux";
    string f3 = "/home/anderson/Documentos/tmp/a.txt";
    string f4 = "/home/anderson/Documentos/tmp/star.csv";

    string filename = "";
    int op = 4;

    switch (op) {
        case 1: filename = f1; break;
        case 2: filename = f2; break;
        case 3: filename = f3; break;
        case 4: filename = f4; break;
        default: filename = f0; break;
    }


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

}

MainWindow::~MainWindow()
{
    delete ui;
}
