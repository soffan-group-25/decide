#include <cassert>
#include <cstdlib>
#include <decide/decide.hpp>
#include <decide/lics.hpp>

// The triangle (0,0), (20, 0), (10, 10) has an area of 100>99
void test_true_instance() {
  Points points{Coordinate(0, 0), Coordinate(1, 1), Coordinate(20, 0),
                Coordinate(1, 1), Coordinate(1, 1), Coordinate(10, 10)};
  Parameters parameters{.AREA1 = 99, .EPTS = 1, .FPTS = 2};
  assert(lic10(points, parameters));
}

void test_false_instance() {
  Points points{Coordinate(0, 0), Coordinate(1, 1), Coordinate(20, 0),
                Coordinate(1, 1), Coordinate(1, 1), Coordinate(10, 10)};
  Parameters parameters{.AREA1 = 101, .EPTS = 1, .FPTS = 2};
  assert(!lic10(points, parameters));
}

int main() {
  test_true_instance();
  test_false_instance();
}
