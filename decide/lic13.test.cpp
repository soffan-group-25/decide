#include <cassert>
#include <decide/lics.hpp>

void test_true_instance() {
  Points points{Coordinate{0, 0},     Coordinate{2, 2},  Coordinate{3, 2},
                Coordinate{100, 100}, Coordinate{4, 4},  Coordinate{3245, 232},
                Coordinate{529, 234}, Coordinate{50, 1}, Coordinate{12, 12}};
  Parameters parameters{.RADIUS1 = 49, .APTS = 2, .BPTS = 3, .RADIUS2 = 7.5};
  assert(lic13(points, parameters));
}

int main() {
  test_true_instance();
  return 0;
}
