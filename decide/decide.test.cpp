#include <cassert>
#include <cstdlib>
#include <decide/decide.hpp>
#include <decide/lics.hpp>
#include <iostream>
#include <sstream>

typedef Connector C;

struct cout_redirect {
  cout_redirect(std::streambuf *new_buffer)
      : old(std::cout.rdbuf(new_buffer)) {}

  ~cout_redirect() { std::cout.rdbuf(old); }

private:
  std::streambuf *old;
};

CMV calculateCMV(Points points, Parameters parameters);
PUM calculatePUM(CMV cmv, LCM lcm);
FUV calculateFUV(PUM &pum, PUV &puv);

/* This tests that every element in CMV is equal to the lic it should be equal
 * to This test should be enough if we assume that the LIC functions themselves
 * are correct, which we can do because they are tested separately
 */
void test_cmv() {
  Points points{Coordinate{0, 0},     Coordinate{2, 2},  Coordinate{3, 2},
                Coordinate{100, 100}, Coordinate{4, 4},  Coordinate{3245, 232},
                Coordinate{529, 234}, Coordinate{50, 1}, Coordinate{12, 12}};
  Parameters parameters{.LENGTH1 = 5,
                        .RADIUS1 = 49,
                        .EPSILON = 3,
                        .AREA1 = 50,
                        .QPTS = 2,
                        .QUADS = 2,
                        .DIST = 6,
                        .NPTS = 3,
                        .KPTS = 1,
                        .APTS = 2,
                        .BPTS = 3,
                        .CPTS = 1,
                        .DPTS = 1,
                        .EPTS = 1,
                        .FPTS = 1,
                        .GPTS = 2,
                        .LENGTH2 = 8,
                        .RADIUS2 = 7.5,
                        .AREA2 = 20};
  CMV cmv = calculateCMV(points, parameters);

  assert(cmv[0] == lic0(points, parameters));
  assert(cmv[1] == lic1(points, parameters));
  assert(cmv[2] == lic2(points, parameters));
  assert(cmv[3] == lic3(points, parameters));
  assert(cmv[4] == lic4(points, parameters));
  assert(cmv[5] == lic5(points, parameters));
  assert(cmv[6] == lic6(points, parameters));
  assert(cmv[7] == lic7(points, parameters));
  assert(cmv[8] == lic8(points, parameters));
  assert(cmv[9] == lic9(points, parameters));
  assert(cmv[10] == lic10(points, parameters));
  assert(cmv[11] == lic11(points, parameters));
  assert(cmv[12] == lic12(points, parameters));
  assert(cmv[13] == lic13(points, parameters));
  assert(cmv[14] == lic14(points, parameters));
}

void assert_pum_equal(PUM &p1, PUM &p2) {
  int n = p1.size();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      assert(p1[i][j] == p2[i][j]);
    }
  }
}

void test_pum() {
  CMV cmv{false, false, true};
  LCM lcm{{C::ANDD, C::NOTUSED, C::ORR},
          {C::NOTUSED, C::NOTUSED, C::ANDD},
          {C::ORR, C::ANDD, C::ORR}};

  PUM expected{{false, true, true}, {true, true, false}, {true, false, true}};
  PUM pum = calculatePUM(cmv, lcm);

  assert_pum_equal(expected, pum);
}

void assert_fuv_equal(FUV &p1, FUV &p2) {
  int n = p1.size();

  for (int i = 0; i < n; i++) {
    assert(p1[i] == p2[i]);
  }
}

void test_fuv() {
  PUM pum{{false, true, true}, {true, true, false}, {true, false, true}};
  PUV puv{false, false, true};

  FUV expected{true, true, false};
  FUV fuv = calculateFUV(pum, puv);

  assert_fuv_equal(expected, fuv);
}

void expect_cout(std::string output, FUV &fuv) {
  std::stringstream buffer;

  {
    // Will redirect all stdout to `buffer` in this scope.
    auto redirect = cout_redirect(buffer.rdbuf());
    decide(fuv);
  }

  // Assert output == buffer
  assert(!buffer.str().compare(output));
}

void test_decide() {
  int n = 15;

  // Test case when all values are true.
  {
    FUV fuv(n, true);
    expect_cout("YES\n", fuv);
  }

  // Test case when all values are false.
  {
    FUV fuv(n, false);
    expect_cout("NO\n", fuv);
  }

  // Test case when all values except one is true.
  for (int i = 0; i < n; i++) {
    FUV fuv(n, true);
    fuv[i] = false;
    expect_cout("NO\n", fuv);
  }
}

int main() {
  test_cmv();
  test_pum();
  test_fuv();
  test_decide();
}
