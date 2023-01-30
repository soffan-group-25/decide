#include <cassert>
#include <cstdlib>
#include <decide/decide.hpp>
#include <decide/lics.hpp>



//test that when QUADS = 1 then it will be true
// this is because any point will at least be in one quad
bool test1_true(){
    Points points{Coordinate(1, 1), Coordinate(0, -1), Coordinate(0, 2),Coordinate(-5, -4), Coordinate(1, -9), Coordinate(0, 0)};
    Parameters param{.QPTS=3, .QUADS=1};
    assert(lic4(points,param));
}
//the last four are different 
bool test2_true(){
    Points points{Coordinate(1, 1), Coordinate(0, 7), Coordinate(16, 9),Coordinate(-8, 4), Coordinate(1, -9), Coordinate(-7, -19)};
    Parameters param{.QPTS=4, .QUADS=3};
    assert(lic4(points,param));
}

//checking that it works if it is only looking for 3 quads
bool test3_true(){
    Points points{Coordinate(1, 1), Coordinate(0, -1), Coordinate(0, 2),Coordinate(-5, -4), Coordinate(1, -9), Coordinate(0, 0)};
    Parameters param{.QPTS=6, .QUADS=2};
    assert(lic4(points,param));
}

//should be false
//all points are the same so they can't be in different quads
bool test4_false(){
    Points points{Coordinate(1, 1), Coordinate(1, 1), Coordinate(1, 1),Coordinate(1, 1), Coordinate(1, 1), Coordinate(1, 1)};
    Parameters param{.QPTS=3, .QUADS=3};
    assert(lic4(points,param));
}

//should be false
//all points are the same so they can't be in different quads
//same as above but with 3 quads
bool test5_false(){
    Points points{Coordinate(1, 1), Coordinate(1, 1), Coordinate(1, 1),Coordinate(1, 1), Coordinate(1, 1), Coordinate(1, 1)};
    Parameters param{.QPTS=3, .QUADS=3};
    assert(lic4(points,param));
}

//tests case where all are in teh same quad so should be false
bool test6_false(){
    Points points{Coordinate(1, -1), Coordinate(1, -2), Coordinate(0, -14),Coordinate(8, -9), Coordinate(9, -7), Coordinate(0, -2)};
    Parameters param{.QPTS=6, .QUADS=3};
    assert(lic4(points,param));
}


//tests cases where there are enough in 3 quads however they are not consecutive
bool test7_false(){
    Points points{Coordinate(1, 1), Coordinate(10, 4), Coordinate(-1, -1),Coordinate(-7, -9), Coordinate(-2, 5), Coordinate(-1, 2)};
    Parameters param{.QPTS=3, .QUADS=3};
    assert (lic4(points,param));
}

int main() {
    test1_true();
    test2_true();
    test3_true();
    test4_false();
    test5_false();
    test6_false();
    test7_false();
}
