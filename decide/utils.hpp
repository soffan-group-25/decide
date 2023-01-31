#ifndef UTILS_H
#define UTILS_H

#include <decide/decide.hpp>

// Add util functions here

// Given three points returns the angle formed by the triangle a --> b --> c
// expressed in radians.
double angle_between_points(Coordinate A, Coordinate B, Coordinate C) {
  if (A.x == B.x && A.y == B.y)
    return 0.0;

  if (A.x == C.x && A.y == C.y)
    return 0.0;

  if (B.x == C.x && B.y == C.y)
    return 0.0;

  double a = atan2(B.y - A.y, B.x - A.x);
  double b = atan2(C.y - A.y, C.x - A.x);
  return b - a;
}

#endif