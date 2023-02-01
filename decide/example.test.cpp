#include <cstdlib>
#include <decide/lics.hpp>

void test() {
  if (true)
    std::exit(EXIT_FAILURE);
}

int main() {
  test();

  return 0;
}
