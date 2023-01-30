#include <cassert>
#include <cstdlib>
#include <decide/decide.hpp>
#include <decide/lics.hpp>

// Three points that fit inside the circle (two have the same y coord)
void test_true_instance_same_y() {
  Points points{Coordinate{1, 3}, Coordinate{3, 3}, Coordinate{2, 1}};
  Parameters parameters{.RADIUS1 = 2};
  assert(lic1(points, parameters));
}

// Three points that fit inside the circle (two have the same x coord)
// Padded with other coordinates.
void test_true_instance_same_x() {
  Points points{Coordinate{67, 43}, Coordinate{23, 23}, Coordinate{2, 0.5},
                Coordinate{2, 4}, Coordinate{4, 2}};
  Parameters parameters{.RADIUS1 = 2};
  assert(lic1(points, parameters));
}

// No distance between the three middle points is greater than the diameter,
// but they are too far apart to fit in the circle. Padded with other
// coordinates to ensure that it loops through the vector properly.
void test_false_instance() {
  Points points{Coordinate{67, 43}, Coordinate{4, 2}, Coordinate{0, 2},
                Coordinate{2, 5}, Coordinate{23, 23}};
  Parameters parameters{.RADIUS1 = 2};
  assert(!lic1(points, parameters));
}

// We need at least three points to meet the condition
void test_too_small_instance() {
  Points points{Coordinate{1, 1}, Coordinate{2, 2}};
  Parameters parameters{.RADIUS1 = 3};
  assert(!lic1(points, parameters));
}

void test_colinear_true() {
  Points points{Coordinate{1, 1}, Coordinate{2, 2}, Coordinate{3, 3}};
  Parameters parameters{.RADIUS1 = 2};
  assert(lic1(points, parameters));
}

void test_colinear_false() {
  Points points{Coordinate{0, 0}, Coordinate{2, 2}, Coordinate{4, 4}};
  Parameters parameters{.RADIUS1 = 2};
  assert(!lic1(points, parameters));
}

int main() {
  test_true_instance_same_x();
  test_true_instance_same_y();
  test_false_instance();
  test_too_small_instance();
  test_colinear_false();
  test_colinear_true();
}
