#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), count(0)
{
    m_label = new QLabel("Clicks count: " + QString::number(count));
    m_button = new QPushButton("Click here");

    m_layout = new QVBoxLayout(this);
    m_layout -> addWidget(m_label) ;
    m_layout -> addWidget(m_button);

    connect(m_button, &QPushButton::clicked, this, &MainWindow::clicks_count);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(m_layout);
    setCentralWidget(centralWidget);
}

void MainWindow::clicks_count()
{
    count ++;
    m_label -> text().clear();
    m_label -> setText("Clicks count: " + QString::number(count));
}

MainWindow::~MainWindow()
{
    delete m_label;
    delete m_button;
    delete m_layout;
}
