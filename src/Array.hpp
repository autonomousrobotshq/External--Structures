#ifndef ARRAY_HPP
# define ARRAY_HPP

/*******************************************************************************
** Array Iterators
*******************************************************************************/

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

/*******************************************************************************
** Array
*******************************************************************************/

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

/*******************************************************************************
** Array Definitions 
*******************************************************************************/

template <typename T>
Array<T>::Array()
	: _store(NULL)
	, _max_size(0)
	, _store_is_internal(false)
{
}

template <typename T>
template <size_t MAX_SIZE>
Array<T>::Array(T (&store)[MAX_SIZE])
	: _store(store)
	, _max_size(MAX_SIZE)
	, _store_is_internal(false)
{
}

template <typename T>
Array<T>::Array(size_t max_size)
	: _store(new T[max_size])
	, _max_size(max_size)
	, _store_is_internal(true)

{
}

template <typename T>
Array<T>::~Array()
{
	if (_store_is_internal) {
		delete[] _store;
	}
}

template <typename T>
template <size_t MAX_SIZE>                                              
void Array<T>::setBackingStore(T (&store)[MAX_SIZE])
{
	static_assert(MAX_SIZE > 0);
	_store = store;
	_max_size = MAX_SIZE;
}

template <typename T>
T & Array<T>::at(size_t index) const
{
	return _store[index];
}

template <typename T>
T & Array<T>::operator[](size_t index)
{
	return _store[index];
}

template <typename T>
const T & Array<T>::operator[](size_t index) const
{
	return _store[index];
}

template <typename T>
T & Array<T>::front()
{
	return (_store[0]);
}

template <typename T>
T & Array<T>::back()
{
	return (_max_size > 0) ? _store[_max_size - 1] : _store[0];
}

template <typename T>
T * Array<T>::data()
{
	return _store;
}

template <typename T>
const T * Array<T>::data() const
{
	return _store;
}

/* iterators */

template <typename T>
typename Array<T>::iterator Array<T>::begin()
{ return iterator(_store); }

template <typename T>
typename Array<T>::iterator Array<T>::end()
{ return iterator(_store, _max_size); }

/* const iterators */

template <typename T>
typename Array<T>::const_iterator Array<T>::begin() const
{ return const_iterator(_store); }

template <typename T>
typename Array<T>::const_iterator Array<T>::end() const
{ return const_iterator(_store, _max_size); }

/* reverse iterators */

template <typename T>
typename Array<T>::reverse_iterator Array<T>::rbegin()
{ return reverse_iterator(_store + (_max_size - 1)); }

template <typename T>
typename Array<T>::reverse_iterator Array<T>::rend()
{ return reverse_iterator(_store, _max_size); }

/* const reverse iterators */

template <typename T>
typename Array<T>::const_reverse_iterator Array<T>::rbegin() const
{ return const_reverse_iterator(_store + (_max_size - 1)); }

template <typename T>
typename Array<T>::const_reverse_iterator Array<T>::rend() const
{ return const_reverse_iterator(_store, (_max_size - 1)); }

/* utility */

template <typename T>
bool Array<T>::empty() const
{
	return _max_size == 0;
}

template <typename T>
size_t Array<T>::size() const
{
	return _max_size;
}

template <typename T>
size_t Array<T>::max_size() const
{
	return _max_size;
}

template <typename T>
void Array<T>::swap(Array & other)
{
	T * tmp = this->_store;
	this->_store = other._store;
	other._store = tmp;
}

template <typename T>
void Array<T>::fill(const T & value)
{
	for (size_t i = 0; i < _max_size; i++)
		_store[i] = value;
}

/*******************************************************************************
** Array Iterator Definitions
*******************************************************************************/

template <typename T>
ArrayIterator<T>::ArrayIterator()
	: _ptr(NULL)
	, _index(0)
{
}

template <typename T>
ArrayIterator<T>::ArrayIterator(T * store_ptr, size_t index)
	: _ptr(store_ptr)
	, _index(index)
{
}

template <typename T>
bool ArrayIterator<T>::operator !=(const ArrayIterator<T> & other) const
{
	return (other._index != this->_index);
}

template <typename T>
bool ArrayIterator<T>::operator ==(const ArrayIterator<T> & other) const
{
	return (other._index == this->_index);
}

template <typename T>
ArrayIterator<T> & ArrayIterator<T>::operator ++()
{
	_index++;
	return *this;
}

template <typename T>
ArrayIterator<T> ArrayIterator<T>::operator ++(int)
{
	_index++;
	return *this;
}

template <typename T>
ArrayIterator<T> & ArrayIterator<T>::operator --()
{
	_index--;
	return *this;
}

template <typename T>
ArrayIterator<T> ArrayIterator<T>::operator --(int)
{
	_index--;
	return *this;
}

template <typename T>
T & ArrayIterator<T>::operator *() const
{
	return *(_ptr + _index);
}

/* ArrayReverseIterator */

template <typename T>
T & ArrayReverseIterator<T>::operator *() const
{
	return *(this->_ptr - this->_index);
}

#endif
