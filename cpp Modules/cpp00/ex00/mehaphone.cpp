#include <iostream>

int main(int argc, char *argv[])
{
	int row;
	int col;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	
	else
	{
		row = 1;
		while (row < argc)
		{
			col = 0;
			while (argv[row][col] != '\0')
			{
				std::cout << (char)toupper(argv[row][col]);
				col++;
			}
			row++;
		}
		std::cout << std::endl;
	}
	return (0);
}