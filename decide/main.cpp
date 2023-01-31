#include <decide/decide.hpp>

int main() {
  LCM lcm;
  PUV puv;

  Points points;
  Parameters parameters;

  CMV cmv = calculateCMV(points, parameters);
  PUM pum = calculatePUM(cmv, lcm);
  FUV fuv = calculateFUV(pum, puv);

  decide(fuv);
  return 0;
}
