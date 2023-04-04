#ifndef USV_H
#define USV_H

#include <stdint.h>

struct USV{
    uint8_t mode = 0; //0-遥控，1-自动
    double lng;
    double lat;
    float x;
    float y;
    float yaw;
    float pitch;
    float heel;
    float velocity;
    uint8_t thrust;
    int8_t rudder;
    uint8_t progress;
    uint8_t satellite;
    float voltage;
    float electric_current;
};
struct DOCK{
    double lng;
    double lat;
    float x;
    float y;
    float yaw;
    float pitch;
    float roll;
    float velocity_number;
    float velocity_course;
    float gyrox;
};

#endif // USV_H
