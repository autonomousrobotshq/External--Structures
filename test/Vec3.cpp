#include <Arduino.h>
#include <ArduinoUnitTests.h>

#include <climits>
#include "Vec3.hpp"

unittest(Vec3)
{
	Vec3<int> vec_a(INT_MIN, 0 , INT_MAX);
	assertTrue(vec_a.x == INT_MIN && vec_a.y == 0 && vec_a.z == INT_MAX);

	Vec3<int> vec_b(INT_MAX, INT_MAX, INT_MAX);
	assertTrue(vec_b != vec_a);
	assertTrue(!(vec_b == vec_a));
	Vec3<int> vec_c(vec_b);
	//assertTrue(vec_b == vec_c);
	//assertTrue(vec_c != vec_a);
	//vec_b = vec_a;
	//assertTrue(vec_b == vec_a);
	//assertTrue(vec_b == vec_c);
}

unittest_main()
