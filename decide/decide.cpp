#include <cassert>
#include <decide/decide.hpp>
#include <decide/lics.hpp>
#include <iostream>

/* A vector with the return values of all the LIC functions
 */
CMV calculateCMV(Points points, Parameters parameters) {
  // Required for all LICs
  assert(points.size() > 1);

  CMV cmv(15);
  cmv[0] = lic0(points, parameters);
  cmv[1] = lic1(points, parameters);
  cmv[2] = lic2(points, parameters);
  cmv[3] = lic3(points, parameters);
  cmv[4] = lic4(points, parameters);
  cmv[5] = lic5(points, parameters);
  cmv[6] = lic6(points, parameters);
  cmv[7] = lic7(points, parameters);
  cmv[8] = lic8(points, parameters);
  cmv[9] = lic9(points, parameters);
  cmv[10] = lic10(points, parameters);
  cmv[11] = lic11(points, parameters);
  cmv[12] = lic12(points, parameters);
  cmv[13] = lic13(points, parameters);
  cmv[14] = lic14(points, parameters);

  return cmv;
}

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
