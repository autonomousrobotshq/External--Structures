#ifndef ARRAY_ITERATORS_HPP
# define ARRAY_ITERATORS_HPP

template <typename T>
class ArrayIterator
{
	public:
		ArrayIterator();
		ArrayIterator(T * store_ptr, size_t index = 0);

		bool operator !=(const ArrayIterator<T> & other) const;
		bool operator ==(const ArrayIterator<T> & other) const;
		ArrayIterator & operator ++();
		ArrayIterator   operator ++(int);
		ArrayIterator & operator --();
		ArrayIterator   operator --(int);
		T & operator *() const;
	protected:
		T * _ptr;
		size_t _index;
};

template <typename T>
class ArrayReverseIterator : public ArrayIterator<T>
{
	public:
		using ArrayIterator<T>::ArrayIterator;
		T & operator *() const;
};

#endif
