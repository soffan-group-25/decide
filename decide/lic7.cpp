#include <cassert>
#include <decide/decide.hpp>

bool lic7(Points points, Parameters parameters) {
  int npts = points.size();
  int kpts = parameters.KPTS;
  double length = parameters.LENGTH1;

  // 1 <= K_PTS <= (NUMPOINTS - 2). According to specification.
  assert(1 <= kpts);
  assert(kpts <= npts - 2);

  // The condition is not met when NUMPOINTS < 3
  if (npts < 3)
    return false;

  Coordinate *last = &points[0];

  // Next point separated by kpts points.
  for (int i = 2 + kpts; i < npts; i++) {
    Coordinate *current = &points[i];
    double distance = current->distance(*last);

    if (distance > length)
      return true;
  }

  return false;
}