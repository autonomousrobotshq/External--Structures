#include <Arduino.h>
#include <ArduinoUnitTests.h>

#include <climits>
#include "Vector.hpp"

unittest(Basics)
{
	const int max_size = 128;
	Vector<int> vec(max_size);

	for (size_t i = 0; i < max_size; i++) {
		vec[i] = i;
		assertEqual(vec[i], i);
	}
}

unittest(UnderlyingData)
{
	const int max_size = 128;
	Vector<int> vec(max_size);

	for (size_t i = 0; i < max_size; i++) {
		vec[i] = i;
	}

	int *int_ptr = vec.data();
	for (size_t i = 0; i < max_size; i++) {
		assertEqual(int_ptr[i], i);
	}
}

unittest(ExternalStore)
{
	const int max_size = 128;
	int store[max_size];

	Vector<int> vec(store);

	for (size_t i = 0; i < max_size; i++) {
		vec[i] = i;
	}
}

unittest(SetExternalStore)
{
	const int max_size = 128;
	int store[max_size];

	Vector<int> vec;
	vec.setBackingStore(store);

	for (size_t i = 0; i < max_size; i++) {
		vec[i] = i;
	}
}

unittest(Iteration)
{
	const int max_size = 128;
	Vector<int> vec(max_size);
	assertTrue(vec.size() == 0);
	vec.fill('A');
	assertTrue(vec.size() == max_size);

	size_t ctr = 0;
	for (int &i : vec) {
		i = ctr++;
		assertEqual(i, vec[i]);
		assertEqual(i, vec.at(i));
	}
	assertEqual(vec.size(), ctr);

	Vector<int>::iterator i;
	ctr = 0;
	for (i = vec.begin(); i != vec.end(); i++) {
		assertEqual(*i, vec[ctr]);
		assertEqual(*i, vec.at(ctr));
		assertEqual(*i, ctr);
		ctr++;
	}
	assertEqual(vec.size(), ctr);
}

unittest(ReverseIteration)
{
	const int max_size = 128;
	Vector<int> vec(max_size);
	assertTrue(vec.size() == 0);
	vec.fill('A');
	assertTrue(vec.size() == max_size);

	size_t ctr = 0;
	for (int &i : vec) {
		i = ctr++;
		assertEqual(i, vec[i]);
		assertEqual(i, vec.at(i));
	}
	assertEqual(vec.size(), ctr);

	Vector<int>::reverse_iterator i;
	ctr = vec.size() - 1;
	for (i = vec.rbegin(); i != vec.rend(); i++) {
		assertEqual(*i, vec[ctr]);
		assertEqual(*i, vec.at(ctr));
		ctr--;
	}
	assertEqual((size_t)-1, ctr);
}

unittest(Fill)
{
	const int max_size = 128;
	Vector<int> vec(max_size);
	vec.fill(0);

	for (size_t i = 0; i < max_size; i++) {
		assertEqual(vec[i], 0);
	}

	vec.fill(INT_MIN);

	for (size_t i = 0; i < max_size; i++) {
		assertEqual(vec[i], INT_MIN);
	}
	assertEqual(vec.size(), max_size);
}

unittest(Swap)
{
	const int max_size = 128;
	Vector<int> vec_A(max_size);
	Vector<int> vec_B(max_size);
	vec_A.fill('A');
	vec_B.fill('B');

	vec_A.swap(vec_B);
	assertEqual(vec_B.back(), 'A');
	assertEqual(vec_A.back(), 'B');
}

unittest(Getters)
{
	const int max_size = 128;
	Vector<int> vec(max_size);

	assertEqual(max_size, vec.max_size());
	assertEqual(0, vec.size());
	assertEqual(true, vec.empty());

	Vector<int> empty_vec;
	assertEqual(0, empty_vec.max_size());
	assertEqual(0, empty_vec.size());
	assertEqual(true, empty_vec.empty());
}

unittest(PushBack)
{
	const int max_size = 128;
	Vector<int> vec(max_size);
	for (int i = 0; i < max_size + 20; i++)
		vec.push_back(i);
	assertEqual(max_size, vec.size());

	int ctr = 0;
	for (int &i : vec)
		assertEqual(ctr++, i);
	assertEqual(ctr, max_size);
}

unittest(FrontBack)
{
	const int max_size = 128;
	Vector<int> vec(max_size);


	vec.front() = 1;
	assertEqual(1, vec[0]);
	vec.back() = 2;
	assertEqual(2, vec[0]);

	vec.push_back(25);
	vec.push_back(25);
	vec.push_back(25);
	vec.front() = 1;
	vec.back() = 2;
	assertEqual(1, vec[0]);
	assertEqual(25, vec[1]);
	assertEqual(2, vec[2]);
}

unittest_main()
