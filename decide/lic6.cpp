#include <cmath>
#include <decide/decide.hpp>

// https://stackoverflow.com/questions/849211/shortest-distance-between-a-point-and-a-line-segment
double distanceFromLine(Coordinate &point, Coordinate &line_start,
                        Coordinate &line_end) {
  double A = point.x - line_start.x;
  double B = point.y - line_start.y;
  double C = line_end.x - line_start.x;
  double D = line_end.y - line_start.y;

  double dot = A * C + B * D;
  double lenSquared = C * C + D * D;
  double param = -1;
  if (lenSquared != 0)
    param = dot / lenSquared;

  double xx, yy;
  if (param < 0) {
    xx = line_start.x;
    yy = line_start.y;
  } else if (param > 1) {
    xx = line_end.x;
    yy = line_end.y;
  } else {
    xx = line_start.x + param * C;
    yy = line_start.y + param * D;
  }

  double dx = point.x - xx;
  double dy = point.y - yy;

  return sqrt(dx * dx + dy * dy);
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