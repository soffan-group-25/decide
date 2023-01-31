#include <decide/decide.hpp>
#include <decide/utils.hpp>

/*There exists at least one set of three consecutive data points which form an
angle such that: angle < (PI−EPSILON) or angle > (PI+EPSILON) The second of the
three consecutive points is always the vertex of the angle. If either the first
point or the last point (or both) coincides with the vertex, the angle is
undefined and the LIC is not satisfied by those three points. (0 ≤ EPSILON <
PI)*/
bool lic2(Points points, Parameters parameters) {
  if (points.size() < 3 || parameters.EPSILON < 0 || parameters.EPSILON >= pi) {
    return false;
  }
  for (int i = 0; i < points.size() - 2; i++) {
    // return false if the end points are the same as the vertex
    if (points[i + 1] == points[i] || points[i + 1] == points[i + 2]) {
      continue;
    }
    double ang = angle_between_points(points[i + 1], points[i], points[i + 2]);
    if (ang < (pi - parameters.EPSILON) || ang > (pi + parameters.EPSILON)) {
      return true;
    }
  }
  return false;
}
