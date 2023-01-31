#include <cassert>
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

FUV calculateFUV(PUM &pum, PUV &puv) {
  int n = pum.size();
  FUV fuv(n);

  for (int i = 0; i < n; i++) {
    fuv[i] = true;

    // FUV[i] should be set to true if PUV[i] is false ...
    if (!puv[i]) {
      fuv[i] = true;
      continue;
    }

    // ... or if all elements in row PUM[i] are true.
    for (int j = 0; j < n; j++) {
      if (!pum[i][j]) {
        // One element is false, exit.
        fuv[i] = false;
        break;
      }
    }
  }

  return fuv;
}

/// This is the main function used to decide whether to launch an interceptor
/// or not. Prints YES or NO to stdout, according to the specification.
void decide(FUV &fuv) {
  int n = fuv.size();
  bool launch = true;

  // All elements in FUV must be true for launch.
  for (int i = 0; i < n; i++) {
    if (!fuv[i]) {
      launch = false;
      break;
    }
  }

  if (launch) {
    std::cout << "YES" << std::endl;
  } else {
    std::cout << "NO" << std::endl;
  }
}