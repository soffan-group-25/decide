#include <decide/decide.hpp>
#include <decide/utils.hpp>

/* There exists at least one set of three consecutive data points that are the
vertices of a triangle with area greater than AREA1. (0 ≤ AREA1)*/

bool lic3(Points points, Parameters param) {
  double area1 = param.AREA1;
  if (area1 < 0 || points.size() < 3) {
    return false;
  }
  for (int i = 0; i < points.size() - 2; i++) {
    Coordinate p1 = points[i];
    Coordinate p2 = points[i + 1];
    Coordinate p3 = points[i + 2];
    double area = triangleArea(p1, p2, p3);
    if (area > area1) {
      return true;
    }
  }

  return false;
}
