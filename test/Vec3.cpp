#include <Arduino.h>
#include <ArduinoUnitTests.h>

#include <climits>
#include <cfloat>
#include <cmath>
#include <Vec3.hpp>

unittest(Basics)
{
	typedef Vec3<double> vec;

	vec a(DBL_MIN, 0, DBL_MAX);
	vec b(DBL_MAX, DBL_MAX, DBL_MAX);

	assertTrue(a.x == DBL_MIN && a.y == 0 && a.z == DBL_MAX);

	assertTrue(b != a);
	assertTrue(!(a == b));

	vec c(b);
	assertTrue(b == c);
	assertTrue(a != c);
	c = a;
	assertTrue(b != c);
	assertTrue(a == c);
	a = b;
	assertTrue(b == a);
	assertTrue(a == b);

	vec d;
	assertTrue(d.x == 0 && d.y == 0 && d.z == 0);
}

unittest(OperatorOverloads)
{
	typedef Vec3<int> vec;

	vec a(1, 2, 3);
	vec b(4, 5, 6);
	
	assertTrue(a + b == vec(5, 7, 9));
	assertTrue(a - b == vec(-3, -3, -3));
	assertTrue(a * b == vec(4, 10, 18));
	assertTrue(a / b == vec(1/4, 2/5, 3/6));
	assertTrue(a % b == vec(1, 2, 3));
	assertTrue(b % a == vec(0, 1, 0));
}

unittest(MathOps)
{
	typedef Vec3<double> vec;

	vec a(1, 2, 3);
	vec b(4, 5, 6);

	vec c;
	c = a; c.Add(b); assertTrue(c == a + b);
	c = a; c.Substract(b); assertTrue(c == a - b);
	for (double i = -100; i < 100; i++) {
		c = a; c.ScalarMultiplication(i); assertTrue(c == vec(i*a.x, i*a.y, i*a.z));
	}
	c = a; double m = c.Mag(); assertTrue(m == sqrt(14));
	c = a; c.Normalize(); assertTrue(c == vec(a.x/m, a.y/m, a.z/m));
	c = a.Dot(b); assertTrue(c == vec(a.x*b.x, a.y*b.y, a.z*b.z));
}

unittest_main()
