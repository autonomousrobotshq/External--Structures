#ifndef VEC3_HPP
#define VEC3_HPP

#include <cmath>

/*
 * Eucleudian point
 */

template <typename T>
class Vec3 {
	public:
	    T		x, y, z;

	  	Vec3() : x(0), y(0), z(0) {}
	  	Vec3(T x, T y, T z) : x(x), y(y), z(z) {}
	  	Vec3(const Vec3 &other) { *this = other; }
	  	~Vec3() {}

		Vec3	&operator=(const Vec3 & other) { x = other.x; y = other.y; z = other.z; return *this; }
	    Vec3	&operator+(const Vec3 & other) const { return Vec3(x + other.x, y + other.y, z + other.z); }
	    Vec3	&operator-(const Vec3 & other) const { return Vec3(x - other.x, y - other.y, z - other.z); }
	    Vec3	&operator*(const Vec3 & other) const { return Vec3(x * other.x, y * other.y, z * other.z); }
	    Vec3	&operator/(const Vec3 & other) const { return Vec3(x / other.x, y / other.y, z / other.z); }
	    Vec3	&operator%(const Vec3 & other) const { return Vec3(x % other.x, y % other.y, z % other.z); }
	    bool	operator==(const Vec3 & other) const { return (x == other.x && y == other.y && z == other.z); }
	    bool	operator!=(const Vec3 & other) const { return (x != other.x || y != other.y || z != other.z); }

		void	Add(const Vec3 & other) { x += other.x; y += other.y; z += other.z; }
		void	Substract(const Vec3 & other) { x -= other.x; y -= other.y; z -= other.z; }
		void	ScalarMultiplication(T s) { x *= s; y *= s; z *= s; }
		T		Mag() const { return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)); }
		void	Normalize() { T mag = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)); x /= mag; y /= mag; z /= mag; }
		Vec3	&Dot(const Vec3 & other) const { Vec3(x * other.x, y * other.y, z * other.z); }
};

#endif
