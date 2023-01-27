#ifndef DECIDE_H
#define DECIDE_H

#include <vector>

// Type declarations
//
typedef enum { ANDD,
               ORR,
               NOTUSED } Connector;

typedef std::pair<double, double> Coordinate;

/* Taken from the header file provided. Redesign as necessary.
 * The specification calls this "inputs to the DECIDE function" but they also
 * declare it as `void DECIDE(void)`, so what they mean by "parameters" is most
 * likely "the data used to decide", not "function arguments". */
typedef struct {
    double LENGTH1;  // LengthinLICs0,7,12
    double RADIUS1;  // RadiusinLICs1,8,13
    double EPSILON;  // DeviationfromPIinLICs2,9
    double AREA1;    // AreainLICs3,10,14
    int QPTS;        // No.ofconsecutivepointsinLIC4
    int QUADS;       // No.ofquadrantsinLIC4
    double DIST;     // DistanceinLIC6
    int NPTS;        // No.ofconsecutivepts.inLIC6
    int KPTS;        // No.ofint.pts.inLICs7,12
    int APTS;        // No.ofint.pts.inLICs8,13
    int BPTS;        // No.ofint.pts.inLICs8,13
    int CPTS;        // No.ofint.pts.inLIC9
    int DPTS;        // No.ofint.pts.inLIC9
    int EPTS;        // No.ofint.pts.inLICs10,14
    int FPTS;        // No.ofint.pts.inLICs10,14
    int GPTS;        // No.ofint.pts.inLIC11
    double LENGTH2;  // MaximumlengthinLIC12
    double RADIUS2;  // MaximumradiusinLIC13
    double AREA2;    // MaximumareainLIC14
} Parameters;

// Constants
static const double pi = 3.1415926535;

// Global variables - defined separately in decide.cpp
//
extern int numpoints;
extern std::vector<Coordinate> points;
extern Parameters parameters;
extern std::vector<std::vector<Connector> > lcm;
extern std::vector<bool> puv;

// Functions
void decide(void);

#endif
