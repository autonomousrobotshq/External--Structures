#include <Vec3.hpp>

typedef Vec3<double> vec;

void setup() {
}

void loop() {
	const double x = 1;
	const double y = 2;
	const double z = 3;

	vec a(x, y, z);

	vec b = vec(x, y, z);
	
	vec c(b); /* c == b */

	/* result is stored in object in which it is called */
	a.Add(b);
	a.Substract(b);
	a.ScalarMultiplication(5);
	a.Normalize();

	vec d = a.Dot(b);
}
