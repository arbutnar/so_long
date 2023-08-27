/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:15:37 by arbutnar          #+#    #+#             */
/*   Updated: 2023/08/27 18:15:37 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class ScalarConverter {

    public:
        void    convert(std::string str);
};

void	isValid(std::string str) {
	if (isalpha(str[0] && str[1])) {
		throw (std::invalid_argument("Invalid Argument\n"));
		return ;
	}
	else if (isalpha(str[0] && !str[1])) {
		std::cout << "Right char arg\n";
		return ;
	}
	else if (!isalpha(str[0] && !str[1]))
		std::cout << "Right num arg\n";
}

void	ScalarConverter::convert(std::string str) {
	try {
		isValid(str);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

int main() {

		ScalarConverter sc;
		sc.convert("s c c ");

	return (0);
}