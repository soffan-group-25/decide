#include <decide/decide.hpp>
#include <cassert>

// There exists at least one set of two data points, separated by exactly K_PTS
// consecutive intervening points, which are a distance greater than the length,
// LENGTH1, apart.
bool criteria1(Points &points, int kpts, int length) {
  int npts = points.size();
  Coordinate *last = &points[0];

  // Next point separated by kpts points.
  for (int i = 1 + kpts; i < npts; i++) {
    Coordinate *current = &points[i];
    double distance = current->distance(*last);

    // There exists a set of two data points separated
    // by kpts points with at least length1 distance apart.
    if (distance > length)
      return true;
  }

  return false;
}

// There exists at least one set of two data point separated by exactly K_PTS
// consecutive intervening points, that are a distance less than the length,
// LENGTH2, apart.
bool criteria2(Points &points, int kpts, int length) {
  int npts = points.size();
  Coordinate &last = points[0];

  // Next point separated by kpts points.
  for (int i = 1 + kpts; i < npts; i++) {
    Coordinate &current = points[i];
    double distance = current.distance(last);

    // There exists a set of two data points separated
    // by kpts points with less than length2 distance apart.
    if (distance < length)
      return true;
  }

  return false;
}

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
  if (!criteria2(points, kpts, length2))
    return false;

  return true;
}
