#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	T *data;
	unsigned int _size;
	T element;
	public:
	Array();
	~Array();
	Array(unsigned int n);
	Array(const Array &other);
	Array &operator=(Array &other);
	T &operator[](unsigned int index);
	const T &operator[](unsigned int index) const;
	unsigned int size() const;
};

#include "Array.tpp"

#endif