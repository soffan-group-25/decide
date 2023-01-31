#include <cassert>
#include <cstdlib>
#include <decide/utils.hpp>

void test_angle_90_degree() {
  double angle = angle_between_points(Coordinate(0, 1), Coordinate(0, 0),
                                      Coordinate(1, 0));
  assert((angle - pi / 4.0) < 1e-10);
}

int main() { test_angle_90_degree(); }