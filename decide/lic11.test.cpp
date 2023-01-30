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

int main() { test_true_instance(); }