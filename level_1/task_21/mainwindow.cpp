#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QGridLayout *layout = new QGridLayout(this);
    QLabel *lab1 = new QLabel("line1: ");
    layout -> addWidget(lab1);
    line1 = new QLineEdit();
    layout -> addWidget(line1);

    QLabel *lab2 = new QLabel("line2: ");
    layout -> addWidget(lab2);
    line2 = new QLineEdit();
    layout -> addWidget(line2);

    button = new QPushButton("Submit");
    layout->addWidget(button);

    connect(button, &QPushButton::clicked, this, &MainWindow::check_validation);



    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

void MainWindow::check_validation()
{
    if(line1 -> text().isEmpty() || line2 -> text().isEmpty() )
    {
        QMessageBox::critical(this, "Error:", "All fields must be filled.");
    }

    else
    {
        QMessageBox::information(this, "Success:", "All fields are filled.");
    }
}

MainWindow::~MainWindow()
{
    delete line1;
    delete line2;
    delete button;
}

