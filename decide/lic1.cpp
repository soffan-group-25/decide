#include <algorithm>
#include <decide/decide.hpp>
#include <decide/utils.hpp>

/// LIC1 is true if there exists "at least one set of three consecutive
/// data points that cannot all be contained within or on a circle of
/// radius RADIUS1".
bool lic1(Points points, Parameters params) {
  if (points.size() < 3) {
    return false;
  }

  for (int i = 1; i < points.size() - 1; i++) {
      if (contained_in_circle(points[i-1], points[i], points[i+1], params.RADIUS1)) {
          return true;
      }
  }

  return false;
}
