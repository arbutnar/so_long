#pragma once
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource {
    public:
        AMateria *inventory[4];
        MateriaSource();
        ~MateriaSource();
        MateriaSource(const MateriaSource &src);
        MateriaSource &operator=(const MateriaSource &src);
        void learnMateria(AMateria* m) ;
        AMateria* createMateria(std::string const & type) ;
};