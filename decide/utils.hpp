#ifndef UTILS_H
#define UTILS_H

#include <algorithm>
#include <cmath>
#include <decide/decide.hpp>

// Add util functions here

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
