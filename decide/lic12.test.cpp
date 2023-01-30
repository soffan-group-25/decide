#include <cassert>
#include <cstdlib>
#include <decide/decide.hpp>
#include <decide/lics.hpp>

// Should be fulfilled because distance
// between (3,3) and (100,100) is greater than LENGTH1=50,
// and distance between (1,1) and (4,4) is less than LENGTH2=2.
void test_true_instance() {
  Points points{Coordinate(1, 1), Coordinate(2, 2), Coordinate(3, 3),
                Coordinate(4, 4), Coordinate(5, 5), Coordinate(100, 100)};
  Parameters parameters{.LENGTH1 = 50, .LENGTH2 = 6, .KPTS = 2};
  assert(lic12(points, parameters));
}

// Should not be fulfilled because distance
// between (3,3) and (100,100), the largest distance, is less than than
// LENGTH1=500.
void test_false_instance1() {
  Points points{Coordinate(1, 1), Coordinate(2, 2), Coordinate(3, 3),
                Coordinate(4, 4), Coordinate(5, 5), Coordinate(100, 100)};
  Parameters parameters{.LENGTH1 = 500, .LENGTH2 = 6, .KPTS = 2};
  assert(!lic12(points, parameters));
}

// Should not be fulfilled because distance
// between (1,1) and (4,4), the smallest distance, is greater than than
// LENGTH2=1.
void test_false_instance2() {
  Points points{Coordinate(1, 1), Coordinate(2, 2), Coordinate(3, 3),
                Coordinate(4, 4), Coordinate(5, 5), Coordinate(100, 100)};
  Parameters parameters{.LENGTH1 = 50, .LENGTH2 = 1, .KPTS = 2};
  assert(!lic12(points, parameters));
}

int main() {
  test_true_instance();
  test_false_instance1();
  test_false_instance2();
}