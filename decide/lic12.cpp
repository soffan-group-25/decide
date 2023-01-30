#include <decide/decide.hpp>

// There exists at least one set of two data points, separated by exactly K_PTS
// consecutive intervening points, which are a distance greater than the length,
// LENGTH1, apart.
bool criteria1(Points &points, int kpts, int length) {
  int npts = points.size();
  Coordinate *last = &points[0];

  // Next point separated by kpts points.
  for (int i = 2 + kpts; i < npts; i++) {
    Coordinate *current = &points[i];
    double distance = current->distance(*last);

    if (distance > length)
      // There exists a set of two data points separated
      // by kpts points with length1 distance apart.
      return true;
  }

  return false;
}

bool criteria2() { return false; } //todo: complete

bool lic12(Points points, Parameters parameters) {
  int npts = points.size();
  int kpts = parameters.KPTS;
  double length1 = parameters.LENGTH1;
  double length2 = parameters.LENGTH2;

  // 0 <= LENGTH2. According to specification.
  assert(0 <= length2);

  // The condition is not met when NUMPOINTS < 3.
  if (npts < 3)
    return false;

  // Criteria 1 must be fulfilled.
  if (!criteria1(points, kpts, length1))
    return false;

  // Criteria 2 must be fulfilled.
  if (!criteria2())
    return false;

  return true;
}