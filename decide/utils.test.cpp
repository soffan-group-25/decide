#include <cassert>
#include <cstdlib>
#include <decide/utils.hpp>

void test_triangle_area() {
  double a = triangleArea(Coordinate(1, 2), Coordinate(-1, 1), Coordinate(0, 5));
  assert(a == 3.5);
}

int main() { test_triangle_area(); }