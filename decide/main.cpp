#include <decide/decide.hpp>

int main() {
  LCM lcm(15, std::vector<Connector>(15));
  PUV puv(15);

  Points points{Coordinate{67, 43}, Coordinate{4, 2}, Coordinate{0, 2},
                Coordinate{2, 5}, Coordinate{23, 23}};
  Parameters parameters{};

  CMV cmv = calculateCMV(points, parameters);

  PUM pum = calculatePUM(cmv, lcm);
  FUV fuv = calculateFUV(pum, puv);

  decide(fuv);
  return 0;
}
