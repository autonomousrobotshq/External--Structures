#include <Arduino.h>
#include <Vector.hpp>

const int store_size = 16;

void setup()
{
}

void loop()
{
	int backing_store[store_size];
	Vector<int> myVector(backing_store);
	
	// alternatively: to let Vector handle allocation
	// Vector<int> myVector(store_size);

	myVector.push_back(1);
	myVector.push_back(2);
	myVector.push_back(3);

	for (int &i : myVector) {
		// handle content
	}

	while (myVector.size() > 0) {
		int i = myVector.peek_back();
		// handle content (clears out vector Fi-Fo)
		myVector.pop_back();
	}
}
