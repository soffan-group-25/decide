#include <decide/decide.hpp>

/* There exists at least one set of three consecutive data points that are the vertices of a triangle
with area greater than AREA1.
(0 ≤ AREA1)*/

bool lic3(Points points, Parameters param){
    double area1=param.AREA1;
    if (area1>0||points.size()<3){
        return false;
    }
    for (int i=0; i <points.size()-2; i++){
        Coordinate p1=points[i];
        Coordinate p2=points[i+1];
        Coordinate p3=points[i+2];
        double area=(p1.x*(p2.y-p3.y)+p2.x*(p3.y-p1.y)+p3.x*(p1.y-p2.y))/2;
        if (area<0){
            area=area*-1;
        }
        if (area>area1){
            return true;
        }
    }

    return false;
}

