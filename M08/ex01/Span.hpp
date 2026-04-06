#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <algorithm>
#include <limits>
#include <stdexcept>
#include <vector>

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
	void addNumber(int Value);
	int shortestSpan();
	int longestSpan();
	template <typename Iterator>
	void addRange(Iterator begin, Iterator end);
};

#endif