#ifndef ARRAY_HPP
# define ARRAY_HPP

#include "Array/ArrayIterators.hpp"

template <typename T>
class Array
{
	public:
		typedef ArrayIterator<T> iterator;
		typedef ArrayIterator<const T> const_iterator;
		typedef ArrayReverseIterator<T> reverse_iterator;
		typedef ArrayReverseIterator<const T> const_reverse_iterator;

		Array();
		template <size_t MAX_SIZE>
		Array(T (&store)[MAX_SIZE]);
		Array(size_t max_size);
		~Array();

		template <size_t MAX_SIZE>
		void setBackingStore(T (&store)[MAX_SIZE]);

		T & at(size_t index) const;
		T & operator[](size_t index);
		const T & operator[](size_t index) const;
		T & front();
		T & back();
		T * data();
		const T * data() const;
		
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;

		reverse_iterator rbegin();
		reverse_iterator rend();

		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;

		bool empty() const;
		size_t size() const;
		size_t max_size() const;

		void swap(Array & other);
		void fill(const T & value);

	protected:
		T * _store;
		size_t _max_size;
	private:
		bool _store_is_internal;
};

#include "Array/ArrayDefinitions.hpp"

#endif
