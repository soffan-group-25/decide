#include <cassert>
#include <cstdlib>
#include <decide/utils.hpp>

void test_angle_90_degree() {
  double angle = angle_between_points(Coordinate(0, 1), Coordinate(0, 0),
                                      Coordinate(1, 1));
  assert((angle - pi / 2.0) < 1e-10);
  assert((angle - pi / 2.0) > -1e-10);
}

/* these should all be 45 degrees, the lines test different orders and rotations
 * of that same angle */
void test_angles_45_degree() {
  double angle1 = angle_between_points(Coordinate(0, 1), Coordinate(0, 0),
                                       Coordinate(1, 0));
  double angle2 = angle_between_points(Coordinate(1, 1), Coordinate(0, 0),
                                       Coordinate(1, 0));
  double angle3 = angle_between_points(Coordinate(-1, -1), Coordinate(-1, 0),
                                       Coordinate(0, 0));

  assert((angle1 - pi / 4.0) < 1e-10);
  assert((angle1 - pi / 4.0) > -1e-10);

  assert((angle2 - pi / 4.0) < 1e-10);
  assert((angle2 - pi / 4.0) > -1e-10);

  assert((angle3 - pi / 4.0) < 1e-10);
  assert((angle3 - pi / 4.0) > -1e-10);
}

void test_triangle_area() {
  double a =
      triangleArea(Coordinate(1, 2), Coordinate(-1, 1), Coordinate(0, 5));
  assert(a == 3.5);
}

int main() {
  test_triangle_area();
  test_angle_90_degree();
  test_angles_45_degree();
}
