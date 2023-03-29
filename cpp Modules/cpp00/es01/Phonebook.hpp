#pragma once

#include "Contact.hpp"

class Phonebook
{
	private:
		Contact contact[8];

	public:
		void	add(void);
		void	search(void);
		void	display(void);
};