#include <decide/decide.hpp>

bool lic10(Points points, Parameters params) {
  int n = points.size();
  int epts = params.EPTS;
  int fpts = params.FPTS;
  double area1 = params.AREA1;

  // End point index.
  int m = n - epts - 1 - fpts - 1;

  for (int i = 0; i < m; i++) {
    Coordinate &first = points[i];
    Coordinate &second = points[i + 1 + epts];
    Coordinate &third = points[i + 1 + epts + 1 + fpts];

    double area =
        abs((first.x * (second.y - third.y) + second.x * (third.y - first.y) +
             third.x * (first.y - second.y)) /
            2);

    if (area > area1)
      return true;
  }

  return false;
}
