#include <cassert>
#include <cstdlib>
#include <decide/decide.hpp>
#include <decide/lics.hpp>

//both areas are wrong 
void test_false_instance1() {
    Points points{Coordinate(1, -2), Coordinate(0, 0), Coordinate(0, 0),
                     Coordinate(3, 4), Coordinate(0, 0), Coordinate(0, 0),Coordinate(0, 0),
                     Coordinate(5, -6), Coordinate(0, 0), Coordinate(0, 0), Coordinate(0, 0),
                     Coordinate(1, -2), Coordinate(0, 0), Coordinate(0, 0),
                     Coordinate(3, 4), Coordinate(0, 0), Coordinate(0, 0),Coordinate(0, 0),
                     Coordinate(5, -6), Coordinate(0, 0), Coordinate(0, 0), Coordinate(0, 0)};
    Parameters parameters{.AREA1 = 500, .EPTS=2, .FPTS=3, .AREA2= 0 };
    assert(lic14(points, parameters));
}

//first area is wrong
void test_false_instance2() {
    Points points{Coordinate(1, -2), Coordinate(0, 0),
                     Coordinate(3, 4), Coordinate(0, 0), 
                     Coordinate(5, -6), Coordinate(0, 0), 
                     Coordinate(1, -2), Coordinate(0, 0), 
                     Coordinate(3, 4), Coordinate(0, 0), 
                     Coordinate(5, -6), Coordinate(0, 0)};
    Parameters parameters{.AREA1 = 500, .EPTS=1, .FPTS=1, .AREA2= 500 };
    assert(lic14(points, parameters));
}


//second area is wrong
void test_false_instance3() {
    Points points{Coordinate(1, -2), Coordinate(0, 0), Coordinate(0, 0),Coordinate(0, 0),
                     Coordinate(3, 4), Coordinate(0, 0), Coordinate(0, 0),
                     Coordinate(5, -6), Coordinate(0, 0), Coordinate(0, 0), Coordinate(0, 0),
                     Coordinate(1, -2), Coordinate(0, 0), Coordinate(0, 0),Coordinate(0, 0),
                     Coordinate(3, 4), Coordinate(0, 0), Coordinate(0, 0),
                     Coordinate(5, -6)};
    Parameters parameters{.AREA1 = 0, .EPTS=3, .FPTS=2, .AREA2= 0 };
    assert(lic14(points, parameters));
}

//not enough points 
//second check
void test_false_instance4() {
    Points points{Coordinate(1, -2), Coordinate(0, 0), Coordinate(0, 0),
                     Coordinate(3, 4), Coordinate(0, 0), Coordinate(0, 0),Coordinate(0, 0),
                     Coordinate(5, -6), Coordinate(0, 0), Coordinate(0, 0), Coordinate(0, 0),
                     Coordinate(1, -2), Coordinate(0, 0), Coordinate(0, 0),
                     Coordinate(3, 4), Coordinate(0, 0), Coordinate(0, 0),Coordinate(0, 0),
                     Coordinate(5, -6), Coordinate(0, 0), Coordinate(0, 0), Coordinate(0, 0)};
    Parameters parameters{.AREA1 = 0, .EPTS=7, .FPTS=18, .AREA2=500  };
    assert(lic14(points, parameters));
}

//not enough points
//first check
void test_false_instance5() {
    Points points{Coordinate(1, -2), Coordinate(0, 0), Coordinate(0, 0)};
    Parameters parameters{.AREA1 = 2, .EPTS=2, .FPTS=2, .AREA2= 0 };
    assert(lic14(points, parameters));
}

//the triangles are different
//smaller triangle shows up first
void test_true_instance1() {
    Points points{Coordinate(1, -2), Coordinate(0, 0), Coordinate(0, 0), Coordinate(0, 0),Coordinate(0, 0),
                     Coordinate(3, 4), Coordinate(0, 0), Coordinate(0, 0),Coordinate(0, 0),Coordinate(0, 0), Coordinate(0, 0), Coordinate(0, 0),
                     Coordinate(1, -6), Coordinate(0, 0), Coordinate(0, 0), Coordinate(0, 0),
                     Coordinate(1, -2), Coordinate(0, 0), Coordinate(0, 0), Coordinate(0, 0), Coordinate(0, 0),
                     Coordinate(3, 4), Coordinate(0, 0), Coordinate(0, 0),Coordinate(0, 0),Coordinate(0, 0), Coordinate(0, 0),Coordinate(0, 0),
                     Coordinate(5, -6), Coordinate(0, 0), Coordinate(0, 0), Coordinate(0, 0)};
    Parameters parameters{.AREA1 = 12, .EPTS=4, .FPTS=6, .AREA2= 6 };
    assert(lic14(points, parameters));
}

//the triangles are different
//larger triangle shows up first
void test_true_instance2() {
    Points points{Coordinate(1, -2), Coordinate(0, 0), Coordinate(0, 0),
                     Coordinate(3, 4), Coordinate(0, 0), Coordinate(0, 0), Coordinate(0, 0), Coordinate(0, 0), Coordinate(0, 0),
                     Coordinate(5, -6), Coordinate(0, 0), Coordinate(0, 0), Coordinate(0, 0),
                     Coordinate(1, -2), Coordinate(0, 0), Coordinate(0, 0),
                     Coordinate(3, 4), Coordinate(0, 0), Coordinate(0, 0), Coordinate(0, 0), Coordinate(0, 0), Coordinate(0, 0),
                     Coordinate(1, -6), Coordinate(0, 0), Coordinate(0, 0), Coordinate(0, 0)};
    Parameters parameters{.AREA1 = 12, .EPTS=2, .FPTS=5, .AREA2= 6 };
    assert(lic14(points, parameters));
}

//there is only one triangle meeting both requirements
void test_true_instance3() {
    Points points{Coordinate(1, -2), Coordinate(0, 0),
                     Coordinate(3, 4), Coordinate(0, 0), Coordinate(0, 0), Coordinate(0, 0), Coordinate(0, 0),
                     Coordinate(5, -6), Coordinate(0, 0), Coordinate(0, 0), Coordinate(0, 0),};
    Parameters parameters{.AREA1 = 12, .EPTS=1, .FPTS=4, .AREA2= 50 };
    assert(lic14(points, parameters));
}

//triangles are overlapping
void test_true_instance4() {
    Points points{Coordinate(1, -2), Coordinate(10, 2), 
                    Coordinate(2, 4), Coordinate(30, 4),
                    Coordinate(5, -6), Coordinate(10, -60),};
    Parameters parameters{.AREA1 = 20, .EPTS=1, .FPTS=1, .AREA2= 20 };
    assert(lic14(points, parameters));
}



int main() {
    test_true_instance1();
    test_true_instance2();
    test_true_instance3();
    test_false_instance1();
    test_false_instance2();
    test_false_instance3();
    test_false_instance4();
}