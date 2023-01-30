#include <cassert>
#include <cstdlib>
#include <decide/decide.hpp>
#include <decide/lics.hpp>

void test_true_instance() {
  Points points{Coordinate(1, 0), Coordinate(0, 0)};
  Parameters parameters{};
  assert(lic5(points, parameters));
}

void test_false_instance() {
  Points points{Coordinate(0, 0), Coordinate(0, 0)};
  Parameters parameters{};
  assert(!lic5(points, parameters));
}

int main() {
  test_true_instance();
  test_false_instance();
}
