#include <Arduino.h>
#include <ArduinoUnitTests.h>

#include <climits>
#include <cfloat>
#include <cmath>
#include <Vec2.hpp>

unittest(Basics)
{
	typedef Vec2<double> vec;

	vec a(DBL_MIN, DBL_MAX);
	vec b(DBL_MAX, DBL_MAX);

	assertTrue(a.x == DBL_MIN && a.y == DBL_MAX);

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
	assertTrue(d.x == 0 && d.y == 0);
}

unittest(OperatorOverloads)
{
	typedef Vec2<int> vec;

	vec a(1, 2);
	vec b(4, 5);
	
	assertTrue(a + b == vec(5, 7));
	assertTrue(a - b == vec(-3, -3));
	assertTrue(a * b == vec(4, 10));
	assertTrue(a / b == vec(1/4, 2/5));
	assertTrue(a % b == vec(1, 2));
	assertTrue(b % a == vec(0, 1));
}

unittest(MathOps)
{
	typedef Vec2<double> vec;

	vec a(1, 2);
	vec b(4, 5);

	vec c;
	c = a; c.Add(b); assertTrue(c == a + b);
	c = a; c.Substract(b); assertTrue(c == a - b);
	for (double i = -100; i < 100; i++) {
		c = a; c.ScalarMultiplication(i); assertTrue(c == vec(i*a.x, i*a.y));
	}
	c = a; double m = c.Mag(); assertTrue(m == sqrt(5));
	c = a; c.Normalize(); assertTrue(c == vec(a.x/m, a.y/m));
	c = a.Dot(b); assertTrue(c == vec(a.x*b.x, a.y*b.y));
}

unittest_main()
