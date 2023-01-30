#include <decide/decide.hpp>

bool lic0(Points points, Parameters parameters) {
    double length = parameters.LENGTH1;
    Coordinate* last = &points[0];
    for (int i = 1; i < points.size(); i++) {
        Coordinate* current = &points[i];
        double distance = 0; // todo: check distance between 2 coordinates
        if(distance > length) { 
            return true;
        }
    }

    return false;
}