#ifndef COORDINATE_H
#define COORDINATE_H
#include "point.h"
#include <QImage>
#include <QString>
#include <QPoint>

class Coordinate
{
public:
    Coordinate();
    Coordinate(QPoint *, int);// 坐标轴top的长度。
    Coordinate(QPoint *, int, int);
    Coordinate(QPoint *, int, int, int);
    Coordinate(QPoint *, int, int, int, int);
   void setScaleXright(int);// X轴right刻度个数
   void setScaleYtop(int);// Y轴top刻度个数
   void setScaleXleft(int);
   void setScaleYdown(int);
   void setScaleXmax(int);// X轴刻度最大数
   void setScaleYmax(int);// Y轴刻度最大数
   void drawCoordinate(QImage *);
   void setxName(QString);// x轴单位名
   void setyName(QString);
   void drawPoint(QPointF, QImage *);
   int getOriginPointX();// 获取原点的X，Y值
   int getOriginPointY();
   int getTop();// 获取Y轴正坐标高度
   int getRight();// 获取X轴正坐标长度
   int getScaleXmax();
   int getScaleYmax();

private:
    int top, right, bottom, left,scaleXright,scaleYtop,scaleXleft,scaleYdown,
        scaleXmax,scaleYmax;
    QString xName,yName;
    QPoint *originPoint;// 坐标原点
};

#endif // COORDINATE_H
