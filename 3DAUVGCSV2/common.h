#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>
#include <QStringList>
#define SAT(a,max,min) (a>max?max:(a<min?min:a))
#define BITREAD(x,n) ((x>>n)&0x01)


struct USV{
    uint8_t mode;
    uint8_t task_id;
    bool autoWorking;

    double lng,lat;
    float x,y;
    float course;
    float velocity;
    uint8_t SVs;
    float HDOP;


    float roll,pitch,yaw;



    float desiredCourse;


    float remoteRudderAngle;
    float remotePropellerPW;


    int _rudderMidPW[4];
    int _propellerMidPW;

    float _Pcourse,_Icourse,_Dcourse,_Loscourse;


};

extern const QStringList taskTypeStrList;
extern const QStringList ModeStrList;


#endif // COMMON_H
