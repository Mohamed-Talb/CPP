#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <iostream>
#include <exception>

template<typename T>
void swap(T &Arg1, T &Arg2)
{
	T tmp = Arg1;
	Arg1 = Arg2;
	Arg2 = tmp; 
}

template<typename T>
T &min(T &Arg1, T &Arg2)
{
	return (Arg1 < Arg2) ? Arg1: Arg2;
}

template<typename T>
T max(T &Arg1, T &Arg2)
{
	return (Arg1 > Arg2) ? Arg1: Arg2;
}

#endif