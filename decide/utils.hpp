#ifndef UTILS_H
#define UTILS_H

#include <algorithm>
#include <cmath>
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

// Calculates the area of a triangle
double triangleArea(Coordinate p1, Coordinate p2, Coordinate p3) {
  // See https://www.omnicalculator.com/math/area-triangle-coordinates
  return (1.0 / 2.0) * abs(p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) +
                           p3.x * (p1.y - p2.y));
}

/// Check whether three points can be contained in a circle of
/// radius RADIUS1
bool contained_in_circle(Coordinate point1, Coordinate point2,
                         Coordinate point3, double RADIUS1) {
  // We first check if the triangle is acute or obtuse
  double lengthA = point1.distance(point2);
  double lengthB = point2.distance(point3);
  double lengthC = point3.distance(point1);
  if (lengthB > lengthA) {
    std::swap(lengthB, lengthA);
  }
  if (lengthC > lengthA) {
    std::swap(lengthC, lengthA);
  }

  // lengthA is now the longest edge, or the hypotenuse

  if (pow(lengthB, 2) + pow(lengthC, 2) < pow(lengthA, 2)) {
    // The triangle is obtuse and the radius is the longest distance
    // divided by two (can be shown with sine and cosine of a given angle)
    double radius = lengthA / 2.0;
    if (radius <= RADIUS1) {
      return true;
    }
  } else {
    // The triangle is acute or right. We find the circumcentre using
    // https://en.wikipedia.org/wiki/Circumscribed_circle#Other_properties
    // Since this radius marks the equidistant length from all points, and
    // a non-obtuse triangle has all points on the smallest circle, we
    // compare this radius to RADIUS1 for the answer
    double diameter =
        2 * lengthA * lengthB * lengthC /
        (sqrt((lengthA + lengthB + lengthC) * (lengthB + lengthC - lengthA) *
              (lengthA + lengthC - lengthB) * (lengthA + lengthB - lengthC)));
    double radius = diameter / 2.0;
    if (radius <= RADIUS1) {
      return true;
    }
  }

  return false;
}

#endif
