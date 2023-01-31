#include <decide/decide.hpp>

bool lic0(Points points, Parameters parameters) {
  double length = parameters.LENGTH1;

  for (int i = 0; i < points.size() - 1; i++) {
    Coordinate *first = &points[i];
    Coordinate *second = &points[i + 1];

    double distance = first->distance(*second);
    if (distance > length) {
      return true;
    }
  }

  return false;
}