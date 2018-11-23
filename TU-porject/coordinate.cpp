#include "coordinate.h"
#include "point.h"
#include <QImage>
#include <QPainter>

Coordinate::Coordinate()
{
    Coordinate(new Point(), 0);
}

Coordinate::Coordinate(Point *point, int top) {
    Coordinate(point, top, top, top, top);
}

Coordinate::Coordinate(Point *point, int top, int right) {
    Coordinate(point, top, right, top, right);
}

Coordinate::Coordinate(Point *point, int top, int right, int bottom) {
    Coordinate(point, top, right, bottom, right);
}

Coordinate::Coordinate(Point *point, int top, int right, int bottom, int left) {
    this->originPoint = point;
    this->top = top;
    this->right = right;
    this->bottom = bottom;
    this->left = left;
    this->scaleYtop = 5;
    this->scaleXright = 10;
    this->scaleYdown = 0;
    this->scaleXleft = 0;
}

void Coordinate::setScaleXright(int scaleXright) {
    this->scaleXright = scaleXright;
}

void Coordinate::setScaleXleft(int scaleXleft) {
    this->scaleXleft = scaleXleft;
}

void Coordinate::setScaleYtop(int scaleYtop) {
     this->scaleYtop = scaleYtop;
}

void Coordinate::setScaleYdown(int scaleYdown) {
     this->scaleYdown = scaleYdown;
}

void Coordinate::setScaleXmax(int scaleXmax) {
    this->scaleXmax = scaleXmax;
}

void Coordinate::setScaleYmax(int scaleYmax) {
    this->scaleYmax = scaleYmax;
}

void Coordinate::setxName(QString xName) {
    this->xName = xName;
}

void Coordinate::setyName(QString yName) {
    this->yName = yName;
}

void Coordinate::drawImage(QImage *qimage){

    QPainter painter(qimage);

    painter.setRenderHint(QPainter::Antialiasing, true);// 反锯齿模式。

    int x=originPoint->getX(),y=originPoint->getY();//确定坐标轴起点坐标

    int xNumber = (this->scaleXmax)/scaleXright;// 每个x轴的刻度的数字
    int yNumber = (this->scaleYmax)/scaleYtop;


    QPen penBlack,penDot;
    penBlack.setWidth(3);
    painter.setPen(penBlack);

    // 画箭头
    painter.drawLine(x+right+20,y,x+right+16,y-5);
    painter.drawLine(x+right+20,y,x+right+16,y+5);
    painter.drawLine(x,y-top-20,x+5,y-top-15);
    painter.drawLine(x,y-top-20,x-5,y-top-15);
    // Y轴刻度字
    for (int i=-scaleYdown-1;i<scaleYtop;i++)
    {
        painter.drawText(x-30,y-(i+0.85)*top/scaleYtop,
                         QString::number((int)(yNumber*(i+1))));
    }
    painter.drawText(x-40,y-top-20,yName);
    // X轴刻度字
    for (int i=-scaleXleft-1;i<scaleXright;i++)
    {
        if (i != -1) { // 设置一点偏移，为了美化
        painter.drawText(x+(i+0.65)*right/scaleXright,
                         y+20,QString::number((int)((i+1)*xNumber)));
        }
    }
    painter.drawText(x+right+30,y+10,xName);

    //绘制坐标轴 坐标轴原点(x,y),为了美化，每条线多加20
    if(top!=0){
         painter.drawLine(x,y,x,y-top-20);
    }
    if(bottom!=0){
         painter.drawLine(x,y,x,y+bottom+20);
    }
    if(right!=0){
         painter.drawLine(x,y,x+right+20,y);
    }
    if(left!=0){
         painter.drawLine(x,y,x-left-20,y);
    }

    penDot.setStyle(Qt::DotLine);
    penDot.setWidth(2);
    penDot.setColor(Qt::blue);
    painter.setPen(penDot);

    // x轴虚线
    for(int i=-scaleXleft-1;i<scaleXright;i++)//分成20份
    {
        if (i != -1){ // 去除坐标轴的虚线。
            if (top!=0 && right!=0 && scaleXright!=0) { // 左上角
                painter.drawLine(x+(i+1)*(right/scaleXright),y,x+(i+1)*(right/scaleXright),y-top-20);
            } if(right!=0 && bottom!=0 && scaleXright!=0) { // 左下角
                painter.drawLine(x+(i+1)*(right/scaleXright),y,x+(i+1)*(right/scaleXright),y+bottom+20);
            } if (bottom!=0 && left!=0 && scaleXleft!=0) { // 右下角
                painter.drawLine(x+(i+1)*(left/scaleXleft),y,x+(i+1)*(left/scaleXleft),y+bottom+20);
            } if (left!=0 && top!=0 && scaleXleft!=0) {  // 右上角
                painter.drawLine(x+(i+1)*(left/scaleXleft),y,x+(i+1)*(left/scaleXleft),y-top-20);
            }
        }

    }
    //y轴虚线
    for(int i=-scaleYdown-1;i<scaleYtop;i++)
    {
        if (i!=-1) { //去除坐标轴的虚线
            if (top!=0 && right!=0 && scaleYtop!=0) { // 左上
                painter.drawLine(x,y-(i+1)*(top/scaleYtop),x+right+20,y-(i+1)*(top/scaleYtop));
            } if (right!=0 && bottom!=0 && scaleYdown!=0) { // 左下
                painter.drawLine(x,y+(i+1)*(bottom/scaleYdown),x+right+20,y+(i+1)*(bottom/scaleYdown));
            } if (bottom!=0 && left!=0 && scaleYdown!=0) { // 右下
                painter.drawLine(x,y+(i+1)*(bottom/scaleYdown),x-left-20,y+(i+1)*(bottom/scaleYdown));
            } if (left!=0 && top!=0 && scaleYtop!=0) { // 右上
                painter.drawLine(x,y-(i+1)*(top/scaleYtop),x-left-20,y-(i+1)*(top/scaleYtop));
            }
        }
    }
}
