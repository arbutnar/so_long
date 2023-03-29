#pragma once

#include <iostream>
#include <string>

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	public:
		Contact();
		void	set_first_name(std::string n);
		void	get_first_name(bool flag);
		void	set_last_name(std::string n);
		void	get_last_name(bool flag);
		void	set_nickname(std::string n);
		void	get_nickname(bool flag);
		void	set_phone_number(std::string n);
		void	get_phone_number(bool flag);
		void	set_darkest_secret(std::string n);
		void	get_darkest_secret(bool flag);
};