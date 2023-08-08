#include "ScalarConverter.hpp"
#include <cstdlib>

void ScalarConverter::convert(std::string str) {
	int 	n;
	float 	f;
	double 	d;
	char	c;
	int 	len = str.length();

	for (int i = 0; i < len; i++)
		if (str[len - 1] == 'f')
			f = std::atof(str.c_str());
		else
	//n = std::atoi(str.c_str());
	//d = std::atof(str.c_str());
	c = static_cast<char>(n);
	if (c >= 32 && c != 127)
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << n << std::endl;
	std::cout << "float: " << f << std::endl;
	std::cout << "double: " << d << std::endl;
	//std::cout << "float: " << static_cast<float>(val) << std::endl;
	//std::cout << "double: " << static_cast<double>(val) << std::endl;
	
}
