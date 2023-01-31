#include <cassert>
#include <decide/decide.hpp>

typedef Connector C;

PUM calculatePUM(CMV cmv, LCM lcm);

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

int main() { test_pum(); }