#include "Array.hpp"
#include <exception>

template <typename T>
Array<T>::Array() : data(NULL), _size(0) {}

template <typename T>
Array<T>::~Array()
{
	delete[] data;
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{	
	data = new T[n]();
}

template <typename T>
Array<T>::Array(const Array<T> &other)
{
	_size = other.size();
	data = new T[_size];
	for(unsigned int i = 0; i < _size; i++)
	{
		data[i] = other[i];
	}	
}

template<typename T>
Array<T> &Array<T>::operator=(Array &other)
{
	if (this != &other)
	{
		_size = other.size();
		delete[] data;
		data = new T[_size];
		for(unsigned int i = 0; i < other.size(); i++)
			data[i] = other[i];
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::out_of_range("OUT OF RANGE: index exceeds Array size");
	return data[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::out_of_range("OUT OF RANGE: index exceeds Array size");
	return data[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

