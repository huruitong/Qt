#ifndef POINT_H
#define POINT_H

class Point
{
public:
    Point();
    Point(int, int);
    void setX(int);
    void setY(int);
    int getX();
    int getY();
private:
    int x, y;
};
#endif // POINT_H
