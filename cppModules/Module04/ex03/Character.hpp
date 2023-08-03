#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

struct Node {
	AMateria *context;
	struct Node *next;
};

class Character: public ICharacter {

	public:
		static Node *head;
		static Node *tail;
		std::string name;
		AMateria *inventory[4];
		Character();
		Character(std::string name);
		~Character();
		Character(const Character &src);
		Character &operator=(const Character &src);

		std::string const &getName() const ;
		void equip(AMateria* m) ;
		static void saveMaterias(AMateria* m);
		static void deleteList();
		void unequip(int idx) ;
		void use(int idx, ICharacter& target);
};
