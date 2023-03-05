#include"calculate.h"

using namespace std;

const uint16_t joint1servoMid = 2805;
const uint16_t joint1servoMax = 3737;
const uint16_t joint1servoMin = 709;
const uint16_t joint2servoMax = 4080;
const uint16_t joint2servoMid = 2706;
const uint16_t joint2servoMin = 480;
const uint16_t joint3servoMax = 2474;
const uint16_t joint3servoMid = 1452;
const uint16_t joint3servoMin = 447;
const uint16_t joint4servoMax = 2671;
const uint16_t joint4servoMin = 1421;

const double rad2degree = 180/3.1415926;
const double degree2rad = 1/rad2degree;

/* Parameters of manipulator */
const double l1 = 0.105;
const double l2 = 0.151;
const double l3 = 0.240;

/* Joint value, aim */
double aimJoint_1, aimJoint_2, aimJoint_3;

/* Current position of End effector */
double posEndeffector_x, posEndeffector_y, posEndeffector_z;

void calcEndeffectorPosition(double angle1,double angle2,double angle3)
{
    double q1, q2, q3;
    q1 = angle1*degree2rad;
    q2 = angle2*degree2rad;
    q3 = angle3*degree2rad;
    posEndeffector_x = l3*(cos(q1)*cos(q2)*cos(q3) - cos(q1)*sin(q2)*sin(q3)) + l2*cos(q1)*cos(q2);
    posEndeffector_y = l3*(sin(q1)*sin(q2)*sin(q3) - cos(q2)*cos(q3)*sin(q1)) - l2*cos(q2)*sin(q1);
    posEndeffector_z = l3*(cos(q2)*sin(q3) + cos(q3)*sin(q2)) - l1 + l2*sin(q2);
}


void calcJointValue(double px, double py, double pz)
{
    double q1, q2, q3;
    q1 = -atan(py/px);
    q3 = -acos(-(l2*l2+l3*l3-(px/cos(q1))*(px/cos(q1))-(pz+l1)*(pz+l1))/(2*l2*l3));
    q2 = -(atan((-pz-l1)/(px/cos(q1))) - asin((l3*sin(-q3))/(sqrt((px/cos(q1))*(px/cos(q1))+(pz+l1)*(pz+l1)))));

    aimJoint_1 = q1*rad2degree;
    aimJoint_2 = q2*rad2degree;
    aimJoint_3 = q3*rad2degree;
}

double *Value3Poly(double pos, double aim) // degree
{
    double AngleErr = aim - pos;
    double a[4]={0.0,0.0,0.0,0.0}; 	 // 3Poly parameters
    double tf=0.0;    				 // final calculation time
    double time = 0.0;
    double AngleCtrlLoopCyc = 0.1;  // calculation step
    int npti;                     //
    int i = 0;


    if (AngleErr>180.0)
    {
        AngleErr = AngleErr - 360.0;
    }
    if (AngleErr<-180.0)
    {
        AngleErr = AngleErr + 360.0;
    }

    tf = Abs_fun(AngleErr)/8.0;  // speed
    npti = ceil(tf/AngleCtrlLoopCyc);

    double *aimAngle = new double[npti]; // the planned angle list

    a[0] = pos;
    a[1] = 0;

    if(Abs_fun(AngleErr) - 0.05 < 0)
    {
        a[2] = 0;
        a[3] = 0;
    }
    else
    {
        a[2] = 3.0/(tf*tf)*AngleErr;
        a[3] = -2.0/(tf*tf*tf)*AngleErr;
    }

    while(time<=tf)
    {
        time += AngleCtrlLoopCyc;
        aimAngle[i] = a[0] + a[1]*time + a[2]*time*time + a[3]*time*time*time;
        aimAngle[i] = aimAngle[i]*degree2rad;
        i++;

    }

    aimAngle[npti-1] = aim*degree2rad;

    for(int i = 0; i < npti; ++i){
        printf("%f ", aimAngle[i]);
    }
    printf("\n");

    return aimAngle;
}

double Abs_fun(double xv)
{
    if (xv > 0)
    {
        return xv;
    }
    else
    {
        return -1.0*xv;
    }
}
