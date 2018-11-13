#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPoint>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    image = QImage(800,800,QImage::Format_RGB32);
    image.fill(qRgb(255,255,255));
    Paint();

}
void MainWindow::Paint()
{
    QPainter painter(&image);
    int a[100];
    int pointx=40,pointy=220;//确定坐标轴起点坐标，这里定义(40,440)
    int width=640-pointx,height=150;//确定坐标轴宽度跟高度
    QString str = ui->textEdit->toPlainText();
    QPoint point1,point2,point0;
    point0.setX(pointx);
    point0.setY(pointy);
    for (int i=0;i<100;i++)
    {
       scanf("%d",&a[i]);
    }
    for (int j=0;j<100;j++){
        if(j>1){
        point1.setX(pointx+a[j-2]);
        point1.setY(pointy-a[j-1]);
        point2.setX(pointx+a[j]);
        point2.setY(pointy-a[j]+1);
        painter.drawLine(point1,point2);
        } else if(j==1) {
        point1.setX(pointx+a[0]);
        point1.setY(pointy-a[1]);
        painter.drawLine(point0,point1);
        }
    }



    QPen penBlack,penDot;
    penBlack.setWidth(3);
    painter.setPen(penBlack);

    // X，Y轴刻度字
    for(int i=-6;i<5;i++)
    {
        if (i == -1){
            painter.drawText(pointx-22,pointy-(i+0.85)*height/5,QString::number((int)(30*(i+1))));
        } else {
        painter.drawText(pointx-30,pointy-(i+0.85)*height/5,QString::number((int)(30*(i+1))));
        }
    }
    painter.drawText(pointx-40,pointy-height-20,QString("V/mV"));

    for(int i=0;i<20;i++)//分成10份
    {
        //选取合适的坐标，绘制一段长度为4的直线，用于表示刻度
        painter.drawText(pointx+(i+0.9)*width/20,
                         pointy+20,QString::number((int)((i+1)*((double)5))));
    }
    painter.drawText(pointx+width+25,pointy+10,QString("T/℃"));
    //绘制坐标轴 坐标轴原点(40，440)

    painter.drawLine(pointx,pointy,width+pointx+20,pointy);//坐标轴x宽度为width
    painter.drawLine(width+pointx+20,pointy,width+pointx+12,pointy-8);
    painter.drawLine(width+pointx+20,pointy,width+pointx+12,pointy+8);

    painter.drawLine(pointx,pointy-height-20,pointx,pointy+height+20);//坐标轴y高度为height
    painter.drawLine(pointx,pointy-height-20,pointx+8,pointy-height-12);
    painter.drawLine(pointx,pointy-height-20,pointx-8,pointy-height-12);

    penDot.setStyle(Qt::DotLine);
    penDot.setWidth(2);
    penDot.setColor(Qt::blue);
    painter.setPen(penDot);

    // x轴线
    for(int i=0;i<20;i++)//分成20份
    {
        //选取合适的坐标，绘制一段直线
        painter.drawLine(pointx+(i+1)*width/20,pointy,pointx+(i+1)*width/20,pointy+height+20);
        painter.drawLine(pointx+(i+1)*width/20,pointy,pointx+(i+1)*width/20,pointy-height-20);
    }
    //y轴线
    for(int i=-6;i<5;i++)
    {
        painter.drawLine(pointx,pointy-(i+1)*height/5,
                         pointx+width+20,pointy-(i+1)*height/5);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
