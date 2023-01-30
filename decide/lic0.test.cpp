#include <cstdlib>
#include <decide/decide.hpp>
#include <decide/lics.hpp>

int main() {
  Points points{Coordinate(1, 1)};
  Parameters parameters{.LENGTH1 = 1};

  if (lic0(points, parameters))
    std::exit(EXIT_FAILURE);
}
