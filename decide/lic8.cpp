#include <decide/decide.hpp>
#include <decide/lics.hpp>
#include <decide/utils.hpp>

/// There exists at least one set of three data points separated by exactly
/// APTS and BPTS consecutive intervening points, respectively, that
/// cannot be contained within or on a circle of radius RADIUS1. The
/// condition is not met when NUMPOINTS < 5.
/// Clarification: we have our point, then APTS points, then our next point,
/// then BPTS, then our last point.
///
/// 1 ≤ APTS, 1 ≤ BPTS
/// APTS + BPTS ≤ (NUMPOINTS − 3)
bool lic8(Points points, Parameters parameters) {
  int apts = parameters.APTS;
  int bpts = parameters.BPTS;
  int npoints = points.size();

  // Condition not met and undefined behaviour respectively; return false
  if (npoints < 5 || apts + bpts > npoints - 3) {
    return false;
  }

  for (int i = 0; i < points.size() - (apts + bpts + 2); ++i) {
    if (contained_in_circle(points[i], points[i + apts + 1],
                            points[i + apts + 1 + bpts + 1],
                            parameters.RADIUS1)) {
      return true;
    }
  }
  return false;
}
