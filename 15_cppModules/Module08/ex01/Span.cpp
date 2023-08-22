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
	: N (n) {
		std::cout << "Span one arg constructor" << std::endl;

}