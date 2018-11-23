#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPoint>
#include <QTextStream>
#include <QDebug>
#include <QTime>
#include <QApplication>
#include "point_service.h"
#include "point.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    imagetop = QImage(800,400,QImage::Format_RGB32);
    imagetop.fill(qRgb(255,255,255));
    imageleft = QImage(390,220,QImage::Format_RGB32);
    imageleft.fill(qRgb(255,255,255));
    imageright = QImage(390,220,QImage::Format_RGB32);
    imageright.fill(qRgb(255,255,255));
    this->cooTop = new Coordinate(new QPoint(50,190),150,600,150,0);
    this->cooleft = new Coordinate(new QPoint(40,190),150,300,0,0);
    this->cooright = new Coordinate(new QPoint(40,110),75,300,75,0);
    paintTop();
    paintLeft();
    paintRight();
}
void MainWindow::paintTop()
{
    cooTop->setScaleXmax(300);
    cooTop->setScaleYmax(150);
    cooTop->setxName("T/°C");
    cooTop->setyName("V/mv");
    cooTop->setScaleYdown(5);
    cooTop->drawCoordinate(&imagetop);
}
void MainWindow::paintLeft()
{
    cooleft->setScaleXmax(900);
    cooleft->setScaleYmax(300);
    cooleft->setxName("t/s");
    cooleft->setyName("T/°C");
    cooleft->drawCoordinate(&imageleft);
}
void MainWindow::paintRight()
{    
    cooright->setScaleXmax(900);
    cooright->setScaleYmax(150);
    cooright->setxName("t/s");
    cooright->setyName("V/mv");
    cooright->setScaleYdown(5);
    cooright->drawCoordinate(&imageright);
}

void MainWindow::on_pushButton_clicked()
{
    Point poi;
    QPointF pointTop,pointLeft,pointRight;
    PointService *poiSer = new PointService;
    for (int i=0; i<100 ; i++){
        poi = poiSer->getOnePoint();
        // 将原点的X，Y再加上传过来的点乘以比例，构成新的点，然后调用drawPoint方法。
        pointTop.setX(cooTop->getOriginPointX() + poi.getVol()
                      *cooTop->getRight()/cooTop->getScaleXmax());
        pointTop.setY(cooTop->getOriginPointY() - poi.getTem()
                      *cooTop->getTop()/cooTop->getScaleYmax());
        pointLeft.setX(cooleft->getOriginPointX() + poi.getTime()
                       *cooleft->getRight()/cooleft->getScaleXmax());
        pointLeft.setY(cooleft->getOriginPointY() - poi.getTem()
                       *cooleft->getTop()/cooleft->getScaleYmax());
        pointRight.setX(cooright->getOriginPointX() + poi.getTime()
                        *cooright->getRight()/cooright->getScaleXmax());
        pointRight.setY(cooright->getOriginPointY() - poi.getVol()
                        *cooright->getTop()/cooright->getScaleYmax());
        cooTop->drawPoint(pointTop,&imagetop);
        cooleft->drawPoint(pointLeft,&imageleft);
        cooright->drawPoint(pointRight,&imageright);
        this->repaint();
        this->sleep(300);
    }
}

void MainWindow::sleep(int msec){
    QTime reachTime = QTime::currentTime().addMSecs(msec);
    while (QTime::currentTime() < reachTime) {
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
