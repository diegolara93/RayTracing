#pragma once
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <memory>

// Constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi{ 3.1415926535897932385 };

inline double degrees_to_radians(double degrees) {
	return degrees * pi / 180.0;
}

inline double random_double()
{
	// return random number 0 <= x < 1
	return std::rand() / (RAND_MAX + 1.0);
}

inline double random_double(double min, double max)
{
	// returns a random real in min <= x < max
	return min + (max - min) * random_double();
}

#include "Color.h"
#include "Interval.h"
#include "Ray.h"
#include "Vec3.h"
