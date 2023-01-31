#include <decide/decide.hpp>

int main() {
  CMV cmv;
  LCM lcm;
  PUV puv;
  
  PUM pum = calculatePUM(cmv, lcm);
  FUV fuv = calculateFUV(pum, puv);

  decide(fuv);
  return 0;
}
