#include <cassert>
#include <cstdlib>
#include <decide/utils.hpp>

void test_angle_90_degree() {
  double angle = angle_between_points(Coordinate(0, 1), Coordinate(0, 0),
                                      Coordinate(1, 0));
  assert((angle - pi / 4.0) < 1e-10);
}

void test_angle_between_0_2pi() {
  double angle1 = angle_between_points(Coordinate(0, 1), Coordinate(0, 0),
                                       Coordinate(1, 0));
  double angle2 = angle_between_points(Coordinate(1, 1), Coordinate(0, 0),
                                       Coordinate(1, 0));
  double angle3 = angle_between_points(Coordinate(-1, -1), Coordinate(0, 0),
                                       Coordinate(1, 0));

  assert((0 <= angle1) && (angle1 < 2 * pi));
  assert((0 <= angle2) && (angle2 < 2 * pi));
  assert((0 <= angle3) && (angle3 < 2 * pi));
}

void test_triangle_area() {
  double a =
      triangleArea(Coordinate(1, 2), Coordinate(-1, 1), Coordinate(0, 5));
  assert(a == 3.5);
}

int main() {
  test_triangle_area();
  test_angle_90_degree();
  test_angle_between_0_2pi();
}
