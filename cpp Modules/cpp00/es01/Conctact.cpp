#include "Contact.hpp"

Contact::Contact()
	: first_name {"None"}, last_name {"None"}, nickname {"None"}, phone_number {"None"}, darkest_secret {"None"} {
}

void	Contact::set_first_name(std::string n)
{
	first_name = n;
}

void Contact::get_first_name(bool flag)
{
	if (flag == 1)
	{
		int i;

		if (first_name.length() < 10)
		{
			std::cout << first_name;
			i = first_name.length();
			while (i < 10)
			{
				std::cout << " ";
				i++;
			}
		}
		else
			std::cout << first_name.substr(0, 9) << ".";
	}
	else
		std::cout << first_name << std::endl;
}

void	Contact::set_last_name(std::string n)
{
	last_name = n;
}

void Contact::get_last_name(bool flag)
{
	if (flag == 1)
	{
		int i;

		if (last_name.length() < 10)
		{
			std::cout << last_name;
			i = last_name.length();
			while (i < 10)
			{
				std::cout << " ";
				i++;
			}
		}
		else
			std::cout << last_name.substr(0, 9) << ".";
	}
	else
		std::cout << last_name << std::endl;
}

void	Contact::set_nickname(std::string n)
{
	nickname = n;
}

void Contact::get_nickname(bool flag)
{
	if (flag == 1)
	{
		int i;

		if (nickname.length() < 10)
		{
			std::cout << nickname;
			i = nickname.length();
			while (i < 10)
			{
				std::cout << " ";
				i++;
			}
		}
		else
			std::cout << nickname.substr(0, 9) << ".";
	}
	else
		std::cout << nickname << std::endl;
}

void	Contact::set_phone_number(std::string n)
{
	phone_number = n;
}

void Contact::get_phone_number(bool flag)
{
	if (flag == 1)
	{
		int i;

		if (phone_number.length() < 10)
		{
			std::cout << phone_number;
			i = phone_number.length();
			while (i < 10)
			{
				std::cout << " ";
				i++;
			}
		}
		else
			std::cout << phone_number.substr(0, 9) << ".";
	}
	else
		std::cout << phone_number << std::endl;
}

void	Contact::set_darkest_secret(std::string n)
{
	darkest_secret = n;
}

void Contact::get_darkest_secret(bool flag)
{
	if (flag == 1)
	{
		int i;

		if (darkest_secret.length() < 10)
		{
			std::cout << darkest_secret;
			i = darkest_secret.length();
			while (i < 10)
			{
				std::cout << " ";
				i++;
			}
		}
		else
			std::cout << darkest_secret.substr(0, 9) << ".";
	}
	else
		std::cout << darkest_secret << std::endl;
}