#ifndef VECTOR_DEFINITIONS_HPP
#define VECTOR_DEFINITIONS_HPP

template <typename T>
Vector<T>::Vector()
	: Array<T>()
	, _size(0)
{
}

template <typename T>
Vector<T>::Vector(size_t max_size)
	: Array<T>(max_size)
	, _size(0)
{
}

template <typename T>
template <size_t MAX_SIZE>
Vector<T>::Vector(T (&store)[MAX_SIZE], size_t size)
	: Array<T>(store)
	, _size(size)
{
}

template <typename T>
void Vector<T>::push_back(const T & item)
{
	if (_size < this->_max_size)
		this->_store[_size++] = item;
}

template <typename T>
T &Vector<T>::peek_back()
{
	return ((_size > 0) ? this->_store[_size-1] : this->_store[0]);
}

template <typename T>
void Vector<T>::pop_back()
{
	if (_size > 0)
		_size--;
}

template <typename T>
void Vector<T>::remove(size_t index)
{
	if (index >= 0 && index < _size)
	{
		memmove(&this->_store[index], &this->_store[index + 1], _size - index - 1);
		_size--;
	}
}

template <typename T>
T & Vector<T>::back()
{
	return this->_store[(_size > 0) ? _size-1 : 0];
}

/*
 * iterators
 */

template <typename T>
typename Array<T>::iterator Vector<T>::end()
{ return typename Array<T>::iterator(this->_store, _size); }

template <typename T>
typename Array<T>::const_iterator Vector<T>::end() const
{ return typename Array<T>::const_iterator(this->_store, _size); }

/* reverse iterators */

template <typename T>
typename Array<T>::reverse_iterator Vector<T>::rbegin()
{ return typename Array<T>::reverse_iterator(this->_store + (_size - 1)); }

template <typename T>
typename Array<T>::reverse_iterator Vector<T>::rend()
{ return typename Array<T>::reverse_iterator(this->_store, _size); }

/* const reverse iterators */

template <typename T>
typename Array<T>::const_reverse_iterator Vector<T>::rbegin() const
{ return typename Array<T>::const_reverse_iterator(this->_store + (_size - 1)); } 

template <typename T>
typename Array<T>::const_reverse_iterator Vector<T>::rend() const
{ return typename Array<T>::const_reverse_iterator(this->_store, (_size - 1)); }

template <typename T>
size_t Vector<T>::size() const
{
	return _size;
}

template <typename T>
bool Vector<T>::empty() const
{
	return _size == 0;
}

template <typename T>
bool Vector<T>::full() const
{
	return _size == this->_max_size;
}

template <typename T>
void Vector<T>::fill(const T & value)
{
	Array<T>::fill(value);
	_size = this->_max_size;
}

#endif
