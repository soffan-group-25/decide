#include <cassert>
#include <cstdlib>
#include <decide/decide.hpp>
#include <decide/lics.hpp>

// Should be fulfilled because points
// (5,5) and (1,1) results in X[j]-X[i]=1-5<0.
void test_true_instance() {
  Points points{Coordinate(5, 5), Coordinate(5, 5), Coordinate(5, 5),
                Coordinate(5, 5), Coordinate(1, 1), Coordinate(5, 5)};
  Parameters parameters{.GPTS = 2};
  assert(lic11(points, parameters));
}

// Should not be fulfilled because
// there is no point in which X[j]-X[i]<0 for any j>i.
void test_false_instance1() {
  Points points{Coordinate(5, 5), Coordinate(5, 5), Coordinate(1, 1),
                Coordinate(5, 5), Coordinate(5, 5), Coordinate(5, 5)};
  Parameters parameters{.GPTS = 2};
  assert(!lic11(points, parameters));
}

void test_false_instance2() {
  Points points{Coordinate(1, 1), Coordinate(2, 2), Coordinate(3, 3),
                Coordinate(4, 4), Coordinate(5, 5), Coordinate(100, 100)};
  Parameters parameters{.GPTS = 2};
  assert(!lic11(points, parameters));
}

int main() {
  test_true_instance();
  test_false_instance1();
  test_false_instance2();
}