#ifndef UTILS_H
#define UTILS_H

#include <decide.hpp>

// Add util functions here

// Calculates the area of a triangle
double triangleArea(Coordinate p1, Coordinate p2, Coordinate p3) {
  // See https://www.omnicalculator.com/math/area-triangle-coordinates
  return (1.0 / 2.0) * abs(p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) +
                           p3.x * (p1.y - p2.y));
}

#endif