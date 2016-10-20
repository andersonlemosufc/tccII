#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "huffman/compress/huffmancompressor.h"
#include "huffman/decompress/huffmandecompressor.h"
#include "xmlparser/streamparser.h"
#include "xmlparser/svgvalidator.h"
#include "tree/patricia.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
