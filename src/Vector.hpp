#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <Array.hpp>

template <typename T>
class Vector : public Array<T>
{
	public:
		Vector();
		Vector(size_t max_size);
		template <size_t MAX_SIZE> Vector(T (&store)[MAX_SIZE], size_t size = 0);
	
		void push_back(const T & item);
		T &peek_back();
		void pop_back();
		void remove(size_t index);

		T & back();

		typename Array<T>::iterator end();
		typename Array<T>::const_iterator end() const;

		typename Array<T>::reverse_iterator rbegin();
		typename Array<T>::reverse_iterator rend();
		typename Array<T>::const_reverse_iterator rbegin() const;
		typename Array<T>::const_reverse_iterator rend() const;

		bool empty() const;
		bool full() const;
		size_t size() const;

		void fill(const T & value);
	private:
		size_t _size;
};

#include "Vector/VectorDefinitions.hpp"

#endif
