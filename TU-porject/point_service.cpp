#include "point_service.h"

// 点服务，生成点
PointService::PointService()
{
    for (int i=0 ; i<100 ; i++) {
        point.setVol(i);
        point.setTem(i);
        point.setTime(i*0.3);
        list.append(point);
    }
}

// 每调用这个方法，获取第一个点，并将获取之后的点移除list
Point PointService::getOnePoint(){

        Point poi = list.first();
        list.pop_front();
        return poi;
}
