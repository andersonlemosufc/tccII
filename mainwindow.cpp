#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString filename = "/home/anderson/Documentos/tmp/a.txt";

    HuffmanCompressor* comp = new HuffmanCompressor();
    comp->compress(filename);
}

MainWindow::~MainWindow()
{
    delete ui;
}
