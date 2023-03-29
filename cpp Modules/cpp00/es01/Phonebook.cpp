#include "Phonebook.hpp"

void	Phonebook::add(void)
{
	std::string  n;
	static int i = 0;

	std::cout << "First Name: ";
	std::cin >> n;
	contact[i].set_first_name(n);
	std::cout << "Last Name: ";
	std::cin >> n;
	contact[i].set_last_name(n);
	std::cout << "Nickame: ";
	std::cin >> n;
	contact[i].set_nickname(n);
	std::cout << "Phone Number: ";
	std::cin >> n;
	contact[i].set_phone_number(n);
	std::cout << "Darkest Secret: ";
	std::cin >> n;
	contact[i].set_darkest_secret(n);
	i += 1;
	if (i == 8)
		i = 0;
}

void	Phonebook::search(void)
{
	int i;

	i = 1;
	while (i < 9)
	{
		std::cout << "|" << i << "         |";
		contact[i - 1].get_first_name(1);
		std::cout << "|";
		contact[i - 1].get_last_name(1);
		std::cout << "|";
		contact[i - 1].get_nickname(1);
		std::cout << "|" << std::endl;
		i++;
	}

}

void	Phonebook::display(void)
{
	char Index;
	int i;

	std::cout << "Select Index: " << std::endl;
	while (1)
	{
		std::cin >> Index;
		i = Index - 49;
		if (Index >= 49 && Index <= 56)
		{
			contact[i].get_first_name(0);
			contact[i].get_last_name(0);
			contact[i].get_nickname(0);
			contact[i].get_phone_number(0);
			contact[i].get_darkest_secret(0);
			break;
		}
		else
			std::cout << "Select Again: " << std::endl;
	}
}