#include "waypoint.h"


Waypoint::Waypoint()
{
    lng = 0;
    lat = 0;
    depth = 0;
}
Waypoint::Waypoint(double _lng, double _lat)
{
    lng = _lng;
    lat = _lat;
    depth = 0;
}
Waypoint::Waypoint(double _lng, double _lat, float _depth)
{
    lng = _lng;
    lat = _lat;
    depth = _depth;
}


