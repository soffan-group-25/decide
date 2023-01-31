#include <decide/decide.hpp>
#include <decide/utils.hpp>

/*There exists at least one set of three data points, separated by exactly E PTS
and F PTS consecutive intervening points, respectively, that are the vertices of
a triangle with area greater than AREA1. In addition, there exist three data
points (which can be the same or different from the three data points just
mentioned) separated by exactly E PTS and F PTS consecutive intervening points,
respectively, that are the vertices of a triangle with area less than AREA2.
Both parts must be true for the LIC to be true. The condition is not met when
NUMPOINTS < 5.
0 ≤ AREA2*/

bool lic14(Points points, Parameters param) {
  int npts = points.size();
  int area1 = param.AREA1;
  int area2 = param.AREA2;
  int epts = param.EPTS;
  int fpts = param.FPTS;

  if (npts < 5 || area2 < 0) {
    return false;
  }

  bool first = false;
  bool second = false;
  double area;

  for (int i = 0; i + epts + fpts + 2 < npts; i++) {
    Coordinate p1 = points[i];
    Coordinate p2 = points[i + epts + 1];
    Coordinate p3 = points[i + epts + fpts + 2];
    area = triangleArea(p1, p2, p3);

    first |= (area > area1);
    second |= (area < area2);
    if (first && second) {
      return true;
    }
  }
  return false;
}
