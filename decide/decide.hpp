#ifndef DECIDE_H
#define DECIDE_H

#include <cmath>
#include <vector>

// Type declarations
//
struct Coordinate;

typedef enum { ANDD, ORR, NOTUSED } Connector;
typedef std::vector<Coordinate> Points;
typedef std::vector<bool> CMV;
typedef std::vector<std::vector<bool>> PUM;
typedef std::vector<std::vector<Connector>> LCM;
typedef std::vector<bool> PUV;
typedef std::vector<bool> FUV;

struct Coordinate {
  double x;
  double y;

  Coordinate(double x, double y) : x(x), y(y) {}

  // Get distance from this coordinate to `other` coordinate.
  double distance(const Coordinate &other) const {
    return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
  }

  // Pointers are only used because `this` defaults to a pointer.
  bool operator==(const Coordinate &c2) const {
    return this->x == c2.x && this->y == c2.y;
  }
  bool operator!=(const Coordinate &c2) { return !(*this == c2); }
};

/* Taken from the header file provided. Redesign as necessary.
 * The specification calls this "inputs to the DECIDE function" but they also
 * declare it as `void DECIDE(void)`, so what they mean by "parameters" is most
 * likely "the data used to decide", not "function arguments". */
typedef struct {
  double LENGTH1 = 0; // LengthinLICs0,7,12
  double RADIUS1 = 0; // RadiusinLICs1,8,13
  double EPSILON = 0; // DeviationfromPIinLICs2,9
  double AREA1 = 0;   // AreainLICs3,10,14
  int QPTS = 2;       // No.ofconsecutivepointsinLIC4
  int QUADS = 1;      // No.ofquadrantsinLIC4
  double DIST = 0;    // DistanceinLIC6
  int NPTS = 3;       // No.ofconsecutivepts.inLIC6
  int KPTS = 1;       // No.ofint.pts.inLICs7,12
  int APTS = 1;       // No.ofint.pts.inLICs8,13
  int BPTS = 1;       // No.ofint.pts.inLICs8,13
  int CPTS = 1;       // No.ofint.pts.inLIC9
  int DPTS = 1;       // No.ofint.pts.inLIC9
  int EPTS = 1;       // No.ofint.pts.inLICs10,14
  int FPTS = 1;       // No.ofint.pts.inLICs10,14
  int GPTS = 1;       // No.ofint.pts.inLIC11
  double LENGTH2 = 0; // MaximumlengthinLIC12
  double RADIUS2 = 0; // MaximumradiusinLIC13
  double AREA2 = 0;   // MaximumareainLIC14
} Parameters;

// Constants
static const double pi = 3.1415926535;

// Functions
void decide(FUV &fuv);
CMV calculateCMV(Points points, Parameters parameters);
PUM calculatePUM(CMV cmv, LCM lcm);
FUV calculateFUV(PUM &pum, PUV &puv);

#endif
