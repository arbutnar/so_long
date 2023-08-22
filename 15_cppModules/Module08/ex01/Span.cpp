/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:49:08 by arbutnar          #+#    #+#             */
/*   Updated: 2023/08/22 23:56:19 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

class Span::Overflow : public std::exception {
	public:
		virtual const char* what() const throw() { return ("Span overflow"); }
};

class Span::SpanNotFound : public std::exception {
	public:
		virtual const char* what() const throw() { return ("Span not found - Error may be: zero or one nums stored "); }
};

Span::Span(unsigned int n)
	: N (n), index (0) {
		std::cout << "Span one arg constructor called" << std::endl;
}

Span::Span(const Span &src) {
	std::cout << "Span copy constructor called" << std::endl;
	*this = src;
}

Span &Span::operator=(const Span &src) {
	std::cout << "Span copy assignment opeartor" << std::endl;
	if (this != &src)  {
		this->N = src.N;
		this->v = src.v;
		this->index = src.index;
	}
	return (*this);
}

Span::~Span() {
	std::cout << "Span deconstructor called" << std::endl;
	v.clear();
}

void	Span::addNumber(int num) {
	if (index >= N)
		throw Span::Overflow();
	v.push_back(num);
	index++;
}

void	Span::printVec() {
	for (unsigned int i = 0; i < N; i++)
		std::cout << v[i] << std::endl;
}

//int Span::shortestSpan() {
//	
//}

int	Span::longestSpan() {
	int min = 0;
	int max = 0;

	for (int i = 0; i < (int)N - 1; i++) {
		if(v[i] > v[i + 1])
			min = v[i + 1];
		if(v[i] < v[i + 1])
			max = v[i + 1];
	}
	std::cout << max << std::endl; 
	std::cout << min << std::endl;
	return (max - min);
}