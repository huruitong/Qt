#ifndef POINT_H
#define POINT_H

class Point
{
public:
    Point();
    Point(int, int, double);
    void setTem(int);
    void setVol(int);
    void setTime(double);
    int getTem();
    int getVol();
    double getTime();
private:
    int tem, vol;
    double time;
};
#endif // POINT_H
