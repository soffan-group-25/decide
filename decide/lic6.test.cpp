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

int main() {
  test_distance_from_line();
  test_distance_from_point();
}