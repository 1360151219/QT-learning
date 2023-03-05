#ifndef WAYPOINT_H
#define WAYPOINT_H

class Waypoint
{
public:
    Waypoint();
    Waypoint(double,double);
    Waypoint(double,double,float);

    double lng;
    double lat;
    float depth;
};

#endif // WAYPOINT_H
