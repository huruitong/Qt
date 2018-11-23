#ifndef POINT_SERVICE_H
#define POINT_SERVICE_H

#include "point.h"
#include <QList>

class PointService
{
public:
    PointService();
    Point getOnePoint();

private:
    QList<Point> list;
    Point point;
};

#endif // POINT_SERVICE_H
