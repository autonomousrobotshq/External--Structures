#include <Vec2.hpp>

typedef Vec2<double> vec;

void setup() {
}

void loop() {
	const double x = 1;
	const double y = 2; 

	vec a(x, y);

	vec b = vec(x, y);
	
	vec c(b); /* c == b */

	/* result is stored in object in which it is called */
	a.Add(b);
	a.Substract(b);
	a.ScalarMultiplication(5);
	a.Normalize();

	vec d = a.Dot(b);
}
