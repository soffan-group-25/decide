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

bool lic9(Points points, Parameters parameters) {
    int c=parameters.CPTS+1;
    int d=parameters.DPTS+1;
    int numpoints= points.size();
    double epsilon=parameters.EPSILON;
    if (numpoints<5|| c<1||d<1||(c+d)>(numpoints-3)){
        return false;
    }
    for (int i=0; i<numpoints; i++){
        if (i+c+d>numpoints){
            return false;
        }
        Coordinate p1=points[i];
        Coordinate p2=points[i+c];
        Coordinate p3=points[i+c+d];
        if (p1==p2||p1==p3){
            continue;
        }

        double ang=angle(p1, p3);

        if (ang<(pi-parameters.EPSILON) || ang>(pi+epsilon)) {
            return true;
        }

    }

    return false;
}

double angle(Coordinate a, Coordinate b){
    double top =(a.x*b.x)+(a.y*b.y);
    double bottom =sqrt(pow(a.x,2)+pow(a.y,2))*sqrt(pow(b.x,2)+pow(b.y,2));
    return acos(top/bottom);
}