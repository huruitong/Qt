#ifndef COORDINATE_H
#define COORDINATE_H
#include "point.h"
#include <QImage>
#include <QString>

class Coordinate
{
public:
    Coordinate();
    Coordinate(Point*,int);// 坐标轴top的长度。
    Coordinate(Point*,int, int);
    Coordinate(Point*,int, int, int);
    Coordinate(Point*,int, int, int, int);
   void setScaleXright(int);// X轴right刻度个数
   void setScaleYtop(int);// Y轴top刻度个数
   void setScaleXleft(int);
   void setScaleYdown(int);
   void setScaleXmax(int);// X轴刻度最大数
   void setScaleYmax(int);// Y轴刻度最大数
   void drawImage(QImage*);
   void setxName(QString);// x轴单位名
   void setyName(QString);

private:
    int top, right, bottom, left,scaleXright,scaleYtop,scaleXleft,scaleYdown,
        scaleXmax,scaleYmax;
    QString xName,yName;
    Point *originPoint;// 坐标原点
};

#endif // COORDINATE_H
