#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QVBoxLayout *vLayout = new QVBoxLayout(ui->centralwidget);
    display = new QLineEdit();
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMinimumHeight(50);
    vLayout->addWidget(display);

    QGridLayout *gridLayout = new QGridLayout();
    vLayout->addLayout(gridLayout);

    QStringList buttons {
        "7", "8", "9", "/",
        "4", "5", "6", "*",
        "1", "2", "3", "-",
        "C", "0", "=", "+"
    };
    int position = 0;
    for(int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            QPushButton *button = new QPushButton(buttons[position]);
            gridLayout->addWidget(button, i, j);
            ++position;

            if (button->text().toInt() != 0 || button->text() == "0")
            {
                connect(button, &QPushButton::clicked, this, &MainWindow::onNumberButton);
            }
            else
            {
                connect(button, &QPushButton::clicked, this, &MainWindow::onPushButton);
            }
        }
    }

    setFixedSize(300, 400);
}

void MainWindow::onNumberButton()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button)
    {
        display->setText(display->text() + button->text());
    }
}

void MainWindow::onPushButton() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button)
    {
        if (button->text() == "=")
        {
            vec.push_back(display->text());
            display->clear();
            display->setText(QString::number(eval()));
            vec.clear();

        }
        else if (button->text() == "C")
        {
            display->clear();
            result = 0;
            vec.clear();
        }
        else
        {
            if (button->text() == "+" || button->text() == "-" || button->text() == "*" || button->text() == "/")
            {
                vec.push_back(display->text());
                vec.push_back(button->text());
                display->clear();
            }
            else
            {
                display->setText(display->text() + button->text());
            }
        }
    }

}

double MainWindow::eval()
{
    if (vec[0] != "-") {
        result += vec[0].toDouble();
    }
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        if (vec[i] == "+") {
            result += vec[i + 1].toDouble();
        }
        else if (vec[i] == "-") {
            result -= vec[i + 1].toDouble();
        }
        else if (vec[i] == "*") {
            result *= vec[i + 1].toDouble();
        }
        else if (vec[i] == "/") {
            result /= vec[i + 1].toDouble();
        }
    }
    return result;
}

MainWindow::~MainWindow()
{
    delete ui;
}
