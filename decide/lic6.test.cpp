#include <cassert>
#include <cmath>
#include <cstdlib>
#include <decide/decide.hpp>
#include <decide/lics.hpp>

double distanceFromLine(Coordinate &point, Coordinate &line_start,
                        Coordinate &line_end);

// The point is closest to the line
void test_distance_from_line() {
  auto point = Coordinate(-2, 5);
  auto start = Coordinate(100, -73.75);
  auto end = Coordinate(-100, 76.25);
  double result = distanceFromLine(point, start, end);
  assert(abs(result - 9.0 / 5.0) < 0.0001);
}

// The point is closest to another point,
// namely sqrt(2) away
void test_distance_from_point() {
  auto point = Coordinate(2, 2);
  auto start = Coordinate(1, 1);
  auto end = Coordinate(0, 0);
  double result = distanceFromLine(point, start, end);
  assert(abs(result - sqrt(2.0)) < 0.0001);
}

// The coordinate (5,11) will be >10 above the line
// created by (0,0), (10, 0).
void test_true_instance() {
  Points points{Coordinate(-1, 0), Coordinate(0, 0), Coordinate(5, 11),
                Coordinate(10, 0), Coordinate(11, 0)};
  Parameters parameters{.NPTS = 1, .DIST = 10.0};
  assert(lic6(points, parameters));
}

// The largest possible distance from a point to a line,
// namely (5,9) to the line (0,0) -> (10, 0) will not be sufficiently
// large for the value of DIST=10.0.
void test_false_instance() {
  Points points{Coordinate(-1, 0), Coordinate(0, 0), Coordinate(5, 9),
                Coordinate(10, 0), Coordinate(11, 0)};
  Parameters parameters{.NPTS = 1, .DIST = 10.0};
  assert(!lic6(points, parameters));
}

int main() {
  test_distance_from_line();
  test_distance_from_point();
  test_true_instance();
  test_false_instance();
}