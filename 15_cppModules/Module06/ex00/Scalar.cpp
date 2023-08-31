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
	: literal (static_cast<std::string>(str)) {
		try {
			setStatus(literal);
		} catch(const std::exception &e) {
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
	if (literal.size() == 1) {
		if (std::isalpha(literal.at(0)))
			return (type = charType);
		else
			return (type = intType);
	}
	long unsigned int	i = 0;
	if (literal.at(0) == '+' || literal.at(0) == '-')
		i += 1;
	for(; i < literal.length( ); i++)
	{
		if (literal.at(i) == '.')
		{
			i += 1;
			for(; i < literal.length( ) - 1; i++)
			{
				if (!std::isdigit( literal.at(i) ))
					return invalidType;
			}
			if (literal.at(i) == 'f')
				return floatType;
			else if (std::isdigit( literal.at(i)))
				return doubleType;
			return invalidType;
		}
		else if(!std::isdigit( literal.at(i) ))
			return invalidType;
	}
	return intType;
}

void	Scalar::convert(std::string literal) {
	std::string c = "";
	int i = 0;
	float f = 0;
	double d = 0;

	if (type == invalidType)
		throw std::invalid_argument("Invalid Argument");
	if (type == charType) {
		std::cout << "char: " << getLiteral() << std::endl;
		std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(literal[0]) << std::endl;
		std::cout << "double: " << static_cast<double>(literal[0]) << std::endl;		
		return ;
	}
	else if (setStatus(literal) == floatType) {
		std::cout << "float\n";
		return ;
	}
	else if (setStatus(literal) == doubleType) {
		std::cout << "double\n";
		return ;
	}
	else
		std::cout << "int\n";

}