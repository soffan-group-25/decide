#include <cassert>
#include <cstdlib>
#include <decide/decide.hpp>
#include <decide/lics.hpp>

// basic true test
void test_true_instance1() {
  Points points{Coordinate(1, -2), Coordinate(3, 4), Coordinate(5, -6)};
  Parameters parameters{.AREA1 = 2};
  assert(lic3(points, parameters));
}

// same as above but with filler before
void test_true_instance2() {
  Points points{Coordinate(0, 0),  Coordinate(0, 0), Coordinate(0, 0),
                Coordinate(1, -2), Coordinate(3, 4), Coordinate(5, -6)};
  Parameters parameters{.AREA1 = 2};
  assert(lic3(points, parameters));
}

void test_false_instance1() {
  Points points{Coordinate(1, 1), Coordinate(1, 1), Coordinate(1, 1)};
  Parameters parameters{.AREA1 = 2};
  assert(!lic3(points, parameters));
}

void test_false_instance2() {
  Points points{Coordinate(1, -2), Coordinate(5, -6)};
  Parameters parameters{.AREA1 = 2};
  assert(!lic3(points, parameters));
}

void test_false_instance3() {
  Points points{Coordinate(1, -2), Coordinate(3, 4), Coordinate(5, -6)};
  Parameters parameters{.AREA1 = 200};
  assert(!lic3(points, parameters));
}

int main() {
  test_true_instance1();
  test_true_instance2();
  test_false_instance1();
  test_false_instance2();
  test_false_instance3();
}
