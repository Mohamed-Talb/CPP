#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
#include <limits>

class Span
{
	private:
    unsigned int N;
	std::vector<int> spanBox;
	public:
    Span();
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();
	void addNumber(int N);
	int shortestSpan();
	int longestSpan();
};

#endif