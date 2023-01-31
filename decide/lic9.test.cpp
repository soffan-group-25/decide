#include <cassert>
#include <cstdlib>
#include <decide/decide.hpp>
#include <decide/lics.hpp>

// base true test
void test_true_instance1() {
  Points points{
      Coordinate(0, 0), Coordinate(5, 5), Coordinate(1, 1),
      Coordinate(5, 5), Coordinate(2, 0), Coordinate(5, 5),
  };
  Parameters parameters{.EPSILON = 0, .CPTS = 1, .DPTS = 1};
  assert(lic9(points, parameters));
}

// same as above but with filler points before
void test_true_instance2() {
  Points points{
      Coordinate(5, 5), Coordinate(2, 0), Coordinate(5, 5),
      Coordinate(0, 0), Coordinate(5, 5), Coordinate(1, 1),
      Coordinate(5, 5), Coordinate(2, 0), Coordinate(5, 5),
  };
  Parameters parameters{.EPSILON = 0, .CPTS = 1, .DPTS = 1};
  assert(lic9(points, parameters));
}

// not enough points
void test_false_instance1() {
  Points points{Coordinate(5, 5), Coordinate(2, 0)};
  Parameters parameters{.EPSILON = 0, .CPTS = 1, .DPTS = 1};
  assert(!lic9(points, parameters));
}

// cpts is unvalid number
void test_false_instance2() {
  Points points{
      Coordinate(5, 5), Coordinate(2, 0), Coordinate(5, 5),
      Coordinate(0, 0), Coordinate(5, 5), Coordinate(1, 1),
      Coordinate(5, 5), Coordinate(2, 0), Coordinate(5, 5),
  };
  Parameters parameters{.EPSILON = 0, .CPTS = 0, .DPTS = 1};
  assert(!lic9(points, parameters));
}

// all points the same
void test_false_instance3() {
  Points points{Coordinate(5, 5), Coordinate(5, 5), Coordinate(5, 5),
                Coordinate(5, 5), Coordinate(5, 5), Coordinate(5, 5),
                Coordinate(5, 5), Coordinate(5, 5)};
  Parameters parameters{.EPSILON = 0, .CPTS = 1, .DPTS = 1};
  assert(!lic9(points, parameters));
}

int main() {
  test_true_instance1();
  test_true_instance2();
  test_false_instance1();
  test_false_instance2();
  test_false_instance3();
}