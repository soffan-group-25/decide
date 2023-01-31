#include <decide/decide.hpp>
#include <math.h>

/*There exists at least one set of three data points separated by exactly C PTS and D PTS
consecutive intervening points, respectively, that form an angle such that:
angle < (PI−EPSILON)
or
angle > (PI+EPSILON)
The second point of the set of three points is always the vertex of the angle. If either the first
point or the last point (or both) coincide with the vertex, the angle is undefined and the LIC
is not satisfied by those three points. When NUMPOINTS < 5, the condition is not met.
1 ≤ C PTS, 1 ≤ D PTS
C PTS+D PTS ≤ NUMPOINTS−3*/

double angle(Coordinate a, Coordinate b, Coordinate c){
    double ax = a.x-b.x;
    double ay=a.y-b.y;
    double bx = a.x-c.x;
    double by = a.y-c.y;
    double top =(ax*bx)+(ay*by);
    double bottom =sqrt(pow(ax,2)+pow(ay,2))*sqrt(pow(bx,2)+pow(by,2));
    return acos(top/bottom);
}
bool lic9(Points points, Parameters parameters) {
    int c=parameters.CPTS+1;
    int d=parameters.DPTS+1;
    int numpoints= points.size();
    double epsilon=parameters.EPSILON;

    if (numpoints<5 || c-1<1||d-1<1||(c+d)>(numpoints-1)){
        return false;
    }
    for (int i=0; i+c+d <numpoints; i++){
        
        if (points[i]==points[i+c]||points[i+c]==points[i+c+d]){
            continue;
        }
        double ang=angle(points[i+c],points[i],points[i+c+d]);
        if (ang<(pi-parameters.EPSILON) || ang>(pi+parameters.EPSILON)){
            return true;
        }

    }

    return false;
}

