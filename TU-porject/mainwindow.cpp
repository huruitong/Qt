#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPoint>
#include <QTextStream>
#include <QThread>
#include <QDebug>
#include <QTimer>
#include <QTime>
#include <QApplication>
#include "coordinate.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    image = QImage(800,800,QImage::Format_RGB32);
    image.fill(qRgb(255,255,255));
    paintTop();
    paintLeft();
    paintRight();

}
void MainWindow::paintTop()
{
    Coordinate *coo = new Coordinate(new Point(40,190),150,600,150,0);
    coo->setScaleXmax(300);
    coo->setScaleYmax(150);
    coo->setxName("T/°C");
    coo->setyName("V/mv");
    coo->setScaleYdown(5);
    coo->drawImage(&image);


}
void MainWindow::paintLeft()
{
    Coordinate *coo2 = new Coordinate(new Point(40,600),150,300,0,0);
    coo2->setScaleXmax(900);
    coo2->setScaleYmax(300);
    coo2->setxName("t/s");
    coo2->setyName("T/°C");
    coo2->drawImage(&image);
}
void MainWindow::paintRight()
{
    Coordinate *coo3 = new Coordinate(new Point(440,525),75,300,75,0);
    coo3->setScaleXmax(900);
    coo3->setScaleYmax(150);
    coo3->setxName("t/s");
    coo3->setyName("V/mv");
    coo3->setScaleYdown(5);
    coo3->drawImage(&image);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QPainter painter(&image);
    QString str = ui->textEdit->toPlainText();
    QPoint point1,point2,point0;

    int pointx=40,pointy=220;
    point0.setX(pointx);
    point0.setY(pointy);
    QTextStream stream(&str);
    QList<int> array;
    QTimer *timer = new QTimer();
    timer->setInterval(30000);
    while (!stream.atEnd()) {
        int number;
        stream >> number;
        array.append(number);
    }
    for (int j=2;j<array.size();j=j+2){
        point1.setX(pointx+array[j-2]*6);
        point1.setY(pointy-array[j-1]);
        point2.setX(pointx+array[j]*6);
        point2.setY(pointy-array[j+1]);
        painter.drawLine(point1,point2);
        qDebug()<<"test";
        this->sleep(300);
        this->repaint();
    }
}

void MainWindow::sleep(int msec){
    QTime reachTime = QTime::currentTime().addMSecs(msec);
    while (QTime::currentTime() < reachTime) {
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }
}
