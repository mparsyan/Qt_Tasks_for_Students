#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    task = new QLineEdit();
    button1 = new QPushButton("Add", this);
    button2 = new QPushButton("Remove", this);
    widget = new QListWidget(this);

    layout -> addWidget(task);
    layout -> addWidget(button1);
    layout -> addWidget(button2);
    layout -> addWidget(widget);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    connect(button1, &QPushButton::clicked, this, &MainWindow::add_task);
    connect(button2, &QPushButton::clicked, this, &MainWindow::remove_task);
}

void MainWindow::add_task()
{
    if(!task -> text().isEmpty())
    {
        widget -> addItem(task -> text());
        task -> clear();
    }
}

void MainWindow::remove_task()
{
    if(widget -> count())
    {
        QListWidgetItem* cur = widget -> currentItem();
        delete widget->takeItem(widget->row(cur));
    }
}

MainWindow::~MainWindow()
{
    delete task;
    delete button1;
    delete button2;
    delete widget;
}

