#include <decide/decide.hpp>
#include <decide/utils.hpp>

/* There exists at least one set of three data points, separated by exactly A
 * PTS and B PTS consecutive intervening points, respectively, that cannot be
 * contained within or on a circle of radius RADIUS1.
 */
bool criteria1(Points &points, int apts, int bpts, double r1) {
  for (int i = 0; i < points.size() - bpts - apts - 2; i++) {
    int idx1 = i;
    int idx2 = idx1 + apts + 1;
    int idx3 = idx2 + bpts + 1;
    if (!contained_in_circle(points[idx1], points[idx2], points[idx3], r1)) {
      return true;
    }
  }
  return false;
}

/* There exists at least one set of three data points (which can be
 * the same or different from the three data points just mentioned) separated by
 * exactly A PTS and B PTS consecutive intervening points, respectively, that
 * can be contained in or on a circle of radius RADIUS2.
 */
bool criteria2(Points &points, int apts, int bpts, double r2) {
  for (int i = 0; i < points.size() - bpts - apts - 2; i++) {
    int idx1 = i;
    int idx2 = idx1 + apts + 1;
    int idx3 = idx2 + bpts + 1;
    if (contained_in_circle(points[idx1], points[idx2], points[idx3], r2)) {
      return true;
    }
  }
  return false;
}

/* Both criteria1 and criteria2 must be true for the LIC to be true. The
 * condition is not met when NUMPOINTS <5. 0 <= RADIUS2
 */
bool lic13(Points points, Parameters parameters) {
  int apts = parameters.APTS;
  int bpts = parameters.BPTS;
  double r1 = parameters.RADIUS1;
  double r2 = parameters.RADIUS2;

  if (points.size() < 5) {
    return false;
  }

  if (!criteria1(points, apts, bpts, r1)) {
    return false;
  }

  if (!criteria2(points, apts, bpts, r2)) {
    return false;
  }

  return true;
}
