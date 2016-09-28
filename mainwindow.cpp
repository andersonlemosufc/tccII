#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString filename = "/home/anderson/Documentos/tmp/aux.txt";

    HuffmanCompressor* comp = new HuffmanCompressor();
    HuffmanDecompressor *dec = new HuffmanDecompressor();
    comp->compress(filename);
    dec->decompress(filename+".huff");

}

MainWindow::~MainWindow()
{
    delete ui;
}
