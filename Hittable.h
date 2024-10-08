#pragma once

class Material;

class Hit_Record{
public:
	Point3 p;
	Vec3 normal;
	std::shared_ptr<Material> mat;
	double t;
	bool front_face;

	void set_face_normal(const Ray& r, const Vec3& outward_normal) {
		// Sets the record normal vector.
		// NOTE: the parameter 'outward_normal' is assumed to have unit length.

		front_face = dot(r.direction(), outward_normal) < 0;
		normal = front_face ? outward_normal : -outward_normal;
	}
};

class Hittable {
public:
	virtual ~Hittable() = default; 

	virtual bool hit(const Ray& r, Interval ray_t, Hit_Record& rec) const = 0;
};
