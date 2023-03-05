#ifndef CALCULATE_H
#define CALCULATE_H
#include <QtMath>
#include <QDebug>
/* Joint value, aim */
extern double aimJoint_1, aimJoint_2, aimJoint_3;

/* Current position of End effector */
extern double posEndeffector_x, posEndeffector_y, posEndeffector_z;
extern const uint16_t joint1servoMid;
extern const uint16_t joint1servoMax;
extern const uint16_t joint1servoMin;
extern const uint16_t joint2servoMax;
extern const uint16_t joint2servoMid;
extern const uint16_t joint2servoMin;
extern const uint16_t joint3servoMax;
extern const uint16_t joint3servoMid;
extern const uint16_t joint3servoMin;
extern const uint16_t joint4servoMax;
extern const uint16_t joint4servoMin;

void calcJointValue(double px, double py, double pz);
double *Value3Poly(double pos, double aim);
void calcEndeffectorPosition(double angle1,double angle2,double angle3);
double Abs_fun(double xv);  // abs function.

#endif // CALCULATE_H
