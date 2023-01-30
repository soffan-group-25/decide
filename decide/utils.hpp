#ifndef UTILS_H
#define UTILS_H

#include <decide/decide.hpp>

// Add util functions here
bool contained_in_circle(Coordinate point1, Coordinate point2,
                         Coordinate point3, double RADIUS1) {
  int diameter = RADIUS1 * 2;

  // If two points are the same, check the distance between the other
  // points (this has to be <= RADIUS1*2 (diameter))
  // If the distance is low enough, we have met the criteria.
  if (point1 == point2) {
    if (point1.distance(point3) <= diameter) {
      return true;
    }
  } else if (point2 == point3) {
    if (point2.distance(point1) <= diameter) {
      return true;
    }
  } else if (point1 == point3) {
    if (point1.distance(point2) <= diameter) {
      return true;
    }
  }

  // If the three points are colinear, we check the longest distance
  // between them and see if that's <= diameter
  double slope12 = (point2.y - point1.y) / (point2.x - point1.x);
  double slope23 = (point3.y - point2.y) / (point3.x - point2.x);
  if (slope12 == slope23) {
    double dist =
        std::max(std::max(point1.distance(point2), point2.distance(point3)),
                 point1.distance(point3));
    if (dist <= diameter) {
      return true;
    }
  }

  // If we have three distinct points (that are not colinear)
  // check if the circle formed by them has a radius less than
  // RADIUS1.
  // Idea for the algorithm came from the following paper by J. Riggs (2017):
  // https://www.mathworks.com/matlabcentral/answers/uploaded_files/251674/Circle%20Calculations.pdf
  double slope = slope12;
  Coordinate pointA = point1;
  Coordinate pointB = point2;
  Coordinate pointC = point3;
  // If points 1 and 2 have the same y, slope_perpendicular will be infinite.
  // To avoid this, we choose points 2 and 3 instead (since we know that they
  // are not all colinear and so 2 and 3 have to have different y values).
  if (slope12 == 0) {
    slope = slope23;
    pointA = point2;
    pointB = point3;
    pointC = point1;
  }

  double midpoint_x = (pointA.x + pointB.x) / 2;
  double midpoint_y = (pointA.y + pointB.y) / 2;
  double slope_perpendicular = -1 / slope;
  double perpendicular_y_intercept =
      midpoint_y - slope_perpendicular * midpoint_x;
  double centre_x_numerator =
      pow(pointC.x, 2) + pow(pointC.y, 2) - pow(pointA.x, 2) -
      pow(pointA.y, 2) + 2 * perpendicular_y_intercept * (pointA.y - pointC.y);
  double centre_x_denominator =
      2 * (pointC.x - pointA.x + slope_perpendicular * (pointC.y - pointA.y));
  double centre_x = centre_x_numerator / centre_x_denominator;
  double centre_y = slope_perpendicular * centre_x + perpendicular_y_intercept;

  double radius = pointA.distance({centre_x, centre_y});
  if (radius <= RADIUS1) {
    return true;
  }

  return false;
}

#endif
