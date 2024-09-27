#pragma once
#include "Interval.h"
#include "Vec3.h"

using Color = Vec3;

inline double linear_to_gamma(double linear_component)
{
	if (linear_component > 0)
		return std::sqrt(linear_component);

	return 0;
}

void write_color(std::ostream& out, const Color& pixel_color) {
	auto r = pixel_color.x();
	auto g = pixel_color.y();
	auto b = pixel_color.z();

	// Apply a linear to gamma transform for gamma 2.
	r = linear_to_gamma(r);
	g = linear_to_gamma(g);
	b = linear_to_gamma(b);

	// Translate the [0,1] component values to the byte range [0,255]
	static const Interval intensity(0.000, 0.999);

	int rbyte = static_cast<int>(256 * intensity.clamp(r));
	int gbyte = static_cast<int>(256 * intensity.clamp(g));
	int bbyte = static_cast<int>(256 * intensity.clamp(b));
	// Print the pixel color components
	out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}