
#pragma once
#include <iostream>
#include <vector>

class Span {

	private:
		unsigned int N;
		std::vector<int> v;

	public:
		class Overflow;
		class SpanNotFound;

		Span(unsigned int N);
		Span(const Span &src);
		~Span();

		operator=(const Span &src);

		void	addNumber(int num);
		void	shortestSpan();
		void	longestSpan();
};