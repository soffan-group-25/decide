#ifndef UTILS_H
#define UTILS_H

#include <algorithm>
#include <cmath>
#include <decide/decide.hpp>

// Add util functions here

// Given three points returns the angle formed by the triangle a --> b --> c
// expressed in radians.
// The first argument is the vertex of the angle
double angle_between_points(Coordinate A, Coordinate B, Coordinate C);

// Calculates the area of a triangle
double triangleArea(Coordinate p1, Coordinate p2, Coordinate p3);

/// Check whether three points can be contained in a circle of
/// radius RADIUS1
bool contained_in_circle(Coordinate point1, Coordinate point2,
                         Coordinate point3, double RADIUS1);

#endif
