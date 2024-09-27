#include "RayTracing.h"



int main()
{
	Hittable_List world;

	auto material_ground = std::make_shared<Lambertian>(Color(0.8, 0.8, 0.0));
	auto material_center = std::make_shared<Lambertian>(Color(0.1, 0.2, 0.5));
	auto material_left = std::make_shared<Metal>(Color(0.8, 0.8, 0.8));
	auto material_right = std::make_shared<Metal>(Color(0.8, 0.6, 0.2));

	world.add(std::make_shared<Sphere>(Point3(0.0, -100.5, -1), 100.0, material_ground));
	world.add(std::make_shared<Sphere>(Point3(0, 0.0, -1.2), 0.5, material_center));
	world.add(std::make_shared<Sphere>(Point3(-1.0, 0.0, -1.0), 0.5, material_left));
	world.add(std::make_shared<Sphere>(Point3(1.0, 0.0, -1.0), 0.5, material_right));

	Camera cam;

	cam.aspect_ratio = 16.0 / 9.0;
	cam.image_width = 400;
	cam.samples_per_pixel = 100;

	cam.render(world);
	return 0;
}
