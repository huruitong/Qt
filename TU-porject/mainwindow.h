#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QTextEdit>
#include <QPushButton>
#include <QTime>
#include <QApplication>
#include "point.h"
#include "coordinate.h"

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
    painter.drawImage(350,30,imagetop);
    painter.drawImage(350,440,imageleft);
    painter.drawImage(760,440,imageright);
    }

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QImage imagetop, imageleft, imageright;
    Coordinate *cooTop, *cooleft, *cooright;

};

#endif // MAINWINDOW_H
