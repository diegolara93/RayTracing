#pragma once

class Interval {
public:
	double min;
	double max;

	Interval() : min(+infinity), max(-infinity) {} // Default interval is empty

	Interval(double min, double max) : min(min), max(max) {}

	double size() const {
		return max - min;
	}
	double contains(double x) const {
		return min <= x && x <= max;
	}
	bool surrounds(double x) const {
		return min < x && x < max;
	}
	static const Interval empty, universe;
};

const Interval Interval::empty = Interval(+infinity, -infinity);
const Interval Interval::universe = Interval(-infinity, +infinity);