#include <cassert>
#include <cstdlib>
#include <decide/decide.hpp>
#include <decide/lics.hpp>

void test_true_instance1() {
    Points points{Coordinate(0, 0), 
                    Coordinate(1, 1),
                    Coordinate(2, 0)};
    Parameters parameters{.EPSILON= 0};
    assert(lic2(points, parameters));
}

void test_false_instance1() {
    Points points{Coordinate(0, 0), 
                    Coordinate(0, 0),
                    Coordinate(0, 0)};
    Parameters parameters{.EPSILON= 0};
    assert(!lic2(points, parameters));
}

void test_false_instance2() {
    Points points{Coordinate(0, 0), 
                    Coordinate(0, 0)};
    Parameters parameters{.EPSILON= 0};
    assert(!lic2(points, parameters));
}
void test_false_instance3() {
    Points points{Coordinate(0, 0), 
                    Coordinate(1, 1),
                    Coordinate(2, 0)};
    Parameters parameters{.EPSILON= 400};
    assert(!lic2(points, parameters));
}



int main() {
    test_true_instance1();
    test_false_instance1();
    test_false_instance2();
    test_false_instance3();
}
