#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLayout>
#include <QListWidget>
#include <QVBoxLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void add_task();
    void remove_task();

private:
    QLineEdit *task;
    QPushButton *button1;
    QPushButton *button2;
    QListWidget *widget;

};
#endif // MAINWINDOW_H
