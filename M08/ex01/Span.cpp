#include "Span.hpp"

Span::Span() : N(0) {}

Span::Span(unsigned int n) : N(n) {}

Span::Span(const Span& other)
{
    *this = other;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
        this->N = other.N;
    return *this;
}

void Span::addNumber(int N)
{
	if (spanBox.size() < static_cast<size_t>(N))
		spanBox.push_back(N);
	else 
		throw std::invalid_argument("ADDNUMBER: Span box is full");
}

int Span::shortestSpan()
{
    if (spanBox.size() < 2)
        throw std::logic_error("Not enough numbers");
    std::sort(spanBox.begin(), spanBox.end());
    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 0; i < spanBox.size() - 1; ++i)
        minSpan = std::min(minSpan, spanBox[i + 1] - spanBox[i]);
    return minSpan;
}
int Span::longestSpan()
{
	if (spanBox.size() < 2)
        throw std::logic_error("Not enough spanBox in span");
	std::vector<int> tmp = spanBox;
	int minVal = *std::min_element(spanBox.begin(), spanBox.end());
    int maxVal = *std::max_element(spanBox.begin(), spanBox.end());
    return maxVal - minVal;
}

Span::~Span() {}