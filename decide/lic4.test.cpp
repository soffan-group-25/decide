#include <cassert>
#include <cstdlib>
#include <decide\decide.hpp>
#include <decide/lics.hpp>



//test that when QUADS = 1 then it will be true
// this is because any point will at least be in one quad
void test1_true(){
Points points{Coordinate(1, 1), Coordinate(0, -1), Coordinate(0, 2),Coordinate(-5, -4), Coordinate(1, -9), Coordinate(0, 0)};
Parameters param{.QPTS=3, .QUADS=1};
assert(lic4(points,param));
}

void test2_true(){
Points points{Coordinate(1, 1), Coordinate(0, -1), Coordinate(0, 2),Coordinate(-5, -4), Coordinate(1, -9), Coordinate(0, 0)};
Parameters param{.QPTS=6, .QUADS=3};
assert(lic4(points,param));
}

void test3_false(){
Points points{Coordinate(1, 1), Coordinate(1, 1), Coordinate(1, 1),Coordinate(1, 1), Coordinate(1, 1), Coordinate(1, 1)};
Parameters param{.QPTS=3, .QUADS=2};
assert(lic4(points,param));
}
