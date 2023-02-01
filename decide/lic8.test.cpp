#include <cassert>
#include <decide/lics.hpp>

void test_true_instance() {
  Points points{Coordinate{0, 0},     Coordinate{2, 2},
                Coordinate{3, 2},     Coordinate{100, 100},
                Coordinate{1234, 42}, Coordinate{3245, 232},
                Coordinate{529, 234}, Coordinate{50, 1}};
  Parameters parameters{.RADIUS1 = 10, .APTS = 2, .BPTS = 3};
  assert(lic8(points, parameters));
}

void test_false_instance() {
  Points points{Coordinate{0, 0},     Coordinate{2, 2},
                Coordinate{3, 2},     Coordinate{100, 100},
                Coordinate{1234, 42}, Coordinate{3245, 232},
                Coordinate{529, 234}, Coordinate{50, 1}};
  Parameters parameters{.RADIUS1 = 10000, .APTS = 2, .BPTS = 3};
  assert(!lic8(points, parameters));
}

int main() {
  test_true_instance();
  test_false_instance();
  return 0;
}
