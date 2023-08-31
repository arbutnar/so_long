/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:06:03 by arbutnar          #+#    #+#             */
/*   Updated: 2023/08/31 16:00:52 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

Scalar::Scalar(char *str)
	: literal (static_cast<std::string>(str)), status ("none") {
		try {
			setStatus(literal);
		} catch(const std::exception &src) {
			std::cout << e.what() << std::endl;
		}
}

Scalar::Scalar(const Scalar &src) {
	*this = src;
}

Scalar &Scalar::operator=(const Scalar &src) {
	if (this != &src)
		this->literal = src.literal;
	return (*this);
}

Scalar::~Scalar() {
}

std::string Scalar::getLiteral() {
	return (this->literal);
}

int Scalar::setStatus(std::string literal) {
	if (literal.size() == 1 && std::isalpha(literal[0]))
		this->status = ""
}

void	Scalar::convert(std::string literal) {
	std::string c = "";
	int i = 0;
	float f = 0;
	double d = 0;

	if (literal.size() == 1 && std::isalpha(literal[0])) {
		std::cout << "char: " << getLiteral() << std::endl;
		std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(literal[0]) << std::endl;
		std::cout << "double: " << static_cast<double>(literal[0]) << std::endl;
		return ;
	}

	i = std::atoi(literal.c_str());
	if (literal[literal.size() -1] == 'f') {
		f = std::atof(literal.c_str());
		d = static_cast<double>(f);
		std::cout << "char: " << static_cast<char>(i) << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << f << std::endl;
		std::cout << "double: " << d << std::endl;
		return ;
	} else {
		std::cout << "Right double arg\n";
		return ;
	}
}