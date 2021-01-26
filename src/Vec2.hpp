#ifndef VEC2_HPP
#define VEC2_HPP

#include <cmath>

/*
 * Euclidean point (x, y)
 */

template <typename T>
class Vec2 {
	public:
	    T		x, y;

	  	Vec2() : x(0), y(0) {}
	  	Vec2(T x, T y, T z) : x(x), y(y) {}
	  	Vec2(const Vec2 &other) { *this = other; }
	  	~Vec2() {}

		Vec2	&operator=(const Vec2 & other) { x = other.x; y = other.y; return *this; }
	    Vec2	&operator+(const Vec2 & other) const { return Vec2(x + other.x, y + other.y); }
	    Vec2	&operator-(const Vec2 & other) const { return Vec2(x - other.x, y - other.y); }
	    Vec2	&operator*(const Vec2 & other) const { return Vec2(x * other.x, y * other.y); }
	    Vec2	&operator/(const Vec2 & other) const { return Vec2(x / other.x, y / other.y); }
	    Vec2	&operator%(const Vec2 & other) const { return Vec2(x % other.x, y % other.y); }
	    bool	operator==(const Vec2 & other) const { return (x == other.x && y == other.y); }
	    bool	operator!=(const Vec2 & other) const { return (x != other.x || y != other.y); }

		void	Add(const Vec2 & other) { x += other.x; y += other.y; }
		void	Substract(const Vec2 & other) { x -= other.x; y -= other.y; }
		void	ScalarMultiplication(T s) { x *= s; y *= s; z *= s; }
		T		Mag() const { return sqrt(pow(x, 2) + pow(y, 2)); }
		void	Normalize() { T mag = sqrt(pow(x, 2) + pow(y, 2)); x /= mag; y /= mag; }
		Vec2	&Dot(const Vec2 & other) const { Vec2(x * other.x, y * other.y); }
};

#endif
