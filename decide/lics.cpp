#include <decide/decide.hpp>
#include <decide/lics.hpp>
#include <iostream>

bool lic0() {
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

bool lic1() {
    return false;
}
bool lic2() {
    return false;
}
bool lic3() {
    return false;
}
bool lic4() {
    return false;
}
bool lic5() {
    return false;
}
bool lic6() {
    return false;
}
bool lic7() {
    return false;
}
bool lic8() {
    return false;
}
bool lic9() {
    return false;
}
bool lic10() {
    return false;
}
bool lic11() {
    return false;
}
bool lic12() {
    return false;
}
bool lic13() {
    return false;
}
bool lic14() {
    return false;
}
