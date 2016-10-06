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

    string filename = "";
    int op = 3;

    switch (op) {
        case 1: filename = f1; break;
        case 2: filename = f2; break;
        case 3: filename = f3; break;
        default: filename = f0; break;
    }

    HuffmanCompressor* comp = new HuffmanCompressor();
    HuffmanDecompressor *dec = new HuffmanDecompressor();
    comp->compress(filename);
    dec->decompress(filename+".huff");

}

MainWindow::~MainWindow()
{
    delete ui;
}
