#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPainter>
#include <QTextEdit>
#include <QPushButton>
#include <QTimer>
#include <QTime>
#include <QApplication>
#include "point.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void paintTop();
    void sleep(int);
    void paintLeft();
    void paintRight();
    ~MainWindow();



protected:
    void paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.drawImage(350,30,image);
    }

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QImage image;


};

#endif // MAINWINDOW_H
