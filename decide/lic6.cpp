#include <cmath>
#include <decide/decide.hpp>

double distanceFromLine(Coordinate &point, Coordinate &line_start,
                        Coordinate &line_end) {
  return 0.0; // todo: implement
}

bool lic6(Points points, Parameters parameters) {
  int npts = parameters.NPTS;
  double dist = parameters.DIST;

  // Condition is not met when NUMPOINTS < 3.
  if (points.size() < 3)
    return false;

  // Loop through all possible lines
  for (int i = 0; i < points.size() - npts - 1; i++) {
    Coordinate &first = points[i];
    Coordinate &second = points[i + npts + 1];

    // Assuming line to compare against is a line segment,
    // therefore bound and not infinite.
    // 
    // If first and second are equal, the calculated
    // distance to compare with DIST is the distance
    // from the coincident point to all other points
    // of the NPTS consecutive points.
    //
    // In other words, just check the distance from
    // the point and the first point in that case.

    // Loop through all possible points
    for (int j = 0; j < npts; j++) {
      Coordinate &point = points[i + j + 1];
      double distance;

      if (first == second) {
        distance = point.distance(first);
      } else {
        distance = distanceFromLine(point, first, second);
      }

      // There is a point further away than DIST from the line segment.
      if (distance > dist)
        return true;
    }
  }

  return false;
}