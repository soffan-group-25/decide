#include <decide/decide.hpp>

/* There exists at least one set of two consecutive data points, (X[i],Y[i]) and
 * (X[j],Y[j]), such that X[j] - X[i] <0. (where i = j-1)*/
bool lic5(Points points, Parameters parameters) {
  for (int j = 1; j < points.size(); j++) {
    if (points[j].x - points[j - 1].x < 0) {
      return true;
    }
  }
  return false;
}
