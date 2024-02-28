#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    label = new QLabel("Hello, World!");
    label->setAlignment(Qt::AlignCenter);

    setWindowTitle("Hello World");
    setCentralWidget(label);

    resize(600,400);
}

MainWindow::~MainWindow()
{
    delete label;
}

