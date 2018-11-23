#include "point.h"


Point::Point() {

}

Point::Point(int tem, int vol, double time) {
    this->tem = tem;
    this->vol = vol;
    this->time = time;
}

int Point::getTem() {
    return this->tem;
}

int Point::getVol() {
    return this->vol;
}
double Point::getTime() {
    return this->time;
}

void Point::setTem(int tem) {
    this->tem = tem;
}

void Point::setVol(int vol) {
    this->vol = vol;
}
void Point::setTime(double time) {
    this->time = time;
}
