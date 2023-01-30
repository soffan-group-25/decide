#include <decide/decide.hpp>

/// There exists at least one set of three data points separated by exactly
/// A_PTS and B_PTS consecutive intervening points, respectively, that
/// cannot be contained within or on a circle of radius RADIUS1. The
/// condition is not met when NUMPOINTS < 5.
/// Clarification: we have our point, then A_PTS points, then our next point,
/// then B_PTS, then our last point.
///
/// 1 ≤ A_PTS, 1 ≤ B_PTS
/// A_PTS + B_PTS ≤ (NUMPOINTS − 3)
bool lic8(Points points, Parameters parameters) {
    int apts = parameters.A_PTS;
    int bpts = parameters.B_PTS;

    for (int i = 0; i < points.size() - (apts+bpts+2); ++i){
        if (contained_in_circle(points[i], points[i+apts+1], points [i+apts+1+bpts+1], parameters.RADIUS1)){
            return true;
        }
    }
    return false;
}
