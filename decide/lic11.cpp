#include <decide/decide.hpp>

// There exists at least one set of two data points, (X[i],Y[i]) and
// (X[j],Y[j]), separated by exactly G_PTS consecutive intervening points, such
// that X[j] - X[i] < 0. (where i<j).
// The condition is not met when NUMPOINTS <3.
//
// 1 <= G_PTS <= NUMPOINTS−2
bool lic11(Points points, Parameters parameters) {
  int npts = points.size();
  int gpts = parameters.GPTS;

  // The condition is not met if npts < 3.
  if (npts < 3)
    return false;

  // Next point separated by kpts points.
  for (int i = 0; i < npts - gpts - 1; i++) {
    Coordinate &first = points[i];
    Coordinate &second = points[i + gpts + 1];
    double value = second.x - first.x; // X[j] - X[i] from specification.

    // There exists a set of two data points j, i separated
    // by gpts points where j.x-i.x<0
    if (value < 0)
      return true;
  }

  return false;
}