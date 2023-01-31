#include <decide/decide.hpp>
#include <decide/lics.hpp>
#include <iostream>

PUM calculatePUM(CMV cmv, LCM lcm) {
  int n = cmv.size();

  // Create square symmetric matrix of size n.
  PUM pum(n, std::vector<bool>(n));

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      bool result;

      switch (lcm[i][j]) {
      case Connector::NOTUSED:
        result = true;
        break;
      case Connector::ANDD:
        result = cmv[i] && cmv[j];
        break;
      case Connector::ORR:
        result = cmv[i] || cmv[j];
        break;
      default:
        // Unreachable
        assert(false);
      }

      // Symmetry
      pum[i][j] = result;
      pum[j][i] = result;
    }
  }

  return pum;
}

/// This is the main function used to decide whether to launch an interceptor
/// or not. Prints YES or NO to stdout, according to the specification.
void decide() {}
