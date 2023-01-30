#include <C:\Users\Hannah Burak\Documents\grunder\14\decide\decide\decide.hpp>

/*There exists at least one set of three data points, separated by exactly E PTS and F PTS consecutive intervening points, respectively, that are the vertices of a triangle with area greater
than AREA1. In addition, there exist three data points (which can be the same or different
from the three data points just mentioned) separated by exactly E PTS and F PTS consecutive intervening points, respectively, that are the vertices of a triangle with area less than
AREA2. Both parts must be true for the LIC to be true. The condition is not met when
NUMPOINTS < 5.
0 ≤ AREA2*/

bool lic14(Points points, Parameters param){
    int npts=sizeof(points);
    int area1= param.AREA1;
    int area2=param.AREA2;
    int e=param.EPTS;
    int f=param.FPTS;
    
    if (npts<5 || area2<= 0){
        return false;
    }

    bool first;
    bool second;
    int area;

    for (int i=0; i<npts; i++){
        if (i+e+f>sizeof(points)){
            return false;
        }
        Coordinate p1=points[i];
        Coordinate p2=points[i+e];
        Coordinate p3=points[i+e+f];
        area=1/2*(p1.x*(p2.y-p3.y)+p2.x*(p3.y-p1.y)+p3.x*(p1.y-p2.y));
        if (area<0){
            area=area*-1;
        }

        if (!first){
            if (area>area1){
                first= true;
            }

        }
        if (!second){
            if (area<area2){
            second= true;
            }       
        }
        else if(first && second){
            return true;
        }
    }
    return false;
}
