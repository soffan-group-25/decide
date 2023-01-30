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

int main() {
  test_true_instance();
}