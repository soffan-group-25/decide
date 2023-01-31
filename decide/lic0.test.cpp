#include <cassert>
#include <cstdlib>
#include <decide/decide.hpp>
#include <decide/lics.hpp>

void test_true_instance() {
  Points points{Coordinate(1, 1), Coordinate(2, 2)};
  Parameters parameters{.LENGTH1 = 1};
  assert(lic0(points, parameters));
}

void test_true_instance2() {
  Points points{Coordinate(1, 1), Coordinate(1.1, 1.1), Coordinate(4, 4)};
  Parameters parameters{.LENGTH1 = 1};
  assert(lic0(points, parameters));
}

void test_false_instance() {
  Points points{Coordinate(1, 1), Coordinate(2, 2)};
  Parameters parameters{.LENGTH1 = 3};
  assert(!lic0(points, parameters));
}

void test_false_instance2() {
  Points points{Coordinate(1, 1), Coordinate(2, 2), Coordinate(3, 3)};
  Parameters parameters{.LENGTH1 = 3};
  assert(!lic0(points, parameters));
}

int main() {
  test_true_instance();
  test_true_instance2();
  test_false_instance();
  test_false_instance2();
}
