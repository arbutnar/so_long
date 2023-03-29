#include "Phonebook.hpp"

int main()
{
	Phonebook phonebook;
	std::string cmd;

	while (1)
	{
		std::cout << "ADD, SEARCH, EXIT" << std::endl;
		std::cin >> cmd;
		if (cmd == "ADD")
			phonebook.add();
		else if (cmd == "SEARCH")
		{
			phonebook.search();
			phonebook.display();
		}
		else if (cmd == "EXIT")
			break;
	}
}
