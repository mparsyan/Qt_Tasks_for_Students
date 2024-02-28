#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QLayout>
#include <QVBoxLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void clicks_count();

private:
    int count;
    QPushButton *m_button;
    QLabel *m_label;
    QVBoxLayout *m_layout;
};
#endif // MAINWINDOW_H
