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

PUM calculatePUM(CMV cmv, LCM lcm);
FUV calculateFUV(PUM &pum, PUV &puv);

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
  test_pum();
  test_fuv();
  test_decide();
}
