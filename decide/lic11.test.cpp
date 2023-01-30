#include <cassert>
#include <cstdlib>
#include <decide/decide.hpp>
#include <decide/lics.hpp>

// Should be fulfilled because points
// (50,50) and (4,4) results in X[j]-X[i]=4-50<0.
void test_true_instance() {
  Points points{Coordinate(50, 50), Coordinate(2, 2), Coordinate(3, 3),
                Coordinate(4, 4),   Coordinate(5, 5), Coordinate(100, 100)};
  Parameters parameters{.GPTS = 2};
  assert(lic11(points, parameters));
}

// Should not be fulfilled because
// there is no point in which X[j]-X[i]<0 for any j>i.
void test_false_instance() {
  Points points{Coordinate(1, 1), Coordinate(2, 2), Coordinate(3, 3),
                Coordinate(4, 4), Coordinate(5, 5), Coordinate(100, 100)};
  Parameters parameters{.GPTS = 2};
  assert(!lic11(points, parameters));
}

int main() {
  test_true_instance();
  test_false_instance();
}