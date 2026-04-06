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
    {
        this->N = other.N;
        this->spanBox = other.spanBox;
    }
    return *this;
}

void Span::addNumber(int value)
{
    if (spanBox.size() >= this->N)
        throw std::runtime_error("Span is full");
    spanBox.push_back(value);
}

int Span::shortestSpan()
{
    if (spanBox.size() < 2)
        throw std::logic_error("Not enough numbers");
    std::vector<int> tmp = spanBox;
    std::sort(tmp.begin(), tmp.end());
    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 0; i < tmp.size() - 1; ++i)
    {
        int diff = tmp[i + 1] - tmp[i];
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}
int Span::longestSpan()
{
    if (spanBox.size() < 2)
        throw std::logic_error("Not enough numbers");

    int minVal = *std::min_element(spanBox.begin(), spanBox.end());
    int maxVal = *std::max_element(spanBox.begin(), spanBox.end());
    return maxVal - minVal;
}

Span::~Span() {}


template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end)
{
    if (spanBox.size() + std::distance(begin, end) > this->N)
        throw std::runtime_error("Not enough space");

    spanBox.insert(spanBox.end(), begin, end);
}