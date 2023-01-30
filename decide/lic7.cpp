#include <cassert>
#include <decide/decide.hpp>

// There exists at least one set of two data points separated by exactly K_PTS
// consecutive intervening points that are a distance greater than the length,
// LENGTH1, apart. The condition is not met when NUMPOINTS <3.
//
// 1<=K_PTS<=(NUMPOINTS−2) 1 <= K_PTS <= (NUMPOINTS - 2). According to
// specification.
bool lic7(Points points, Parameters parameters) {
  int npts = points.size();
  int kpts = parameters.KPTS;
  double length = parameters.LENGTH1;

  // The condition is not met when NUMPOINTS < 3
  if (npts < 3)
    return false;

  // Next point separated by kpts points.
  for (int i = 0; i < npts - kpts; i++) {
    Coordinate &first = points[i];
    Coordinate &second = points[i + kpts];
    double distance = first.distance(second);

    if (distance > length)
      return true;
  }

  return false;
}