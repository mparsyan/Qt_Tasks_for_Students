#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void onNumberButton();
    void onPushButton();


private:
    Ui::MainWindow *ui;
    QLineEdit *display;
    std::vector<QString> vec;
    double result = 0.0;
    double eval();
};
#endif // MAINWINDOW_H
