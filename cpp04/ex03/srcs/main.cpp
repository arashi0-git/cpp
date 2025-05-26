#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
IMateriaSource* src = new MateriaSource();
src->learnMateria(new Ice());
std::cout << "-------------------------" << std::endl;
src->learnMateria(new Cure());
std::cout << "-------------------------" << std::endl;
ICharacter* me = new Character("me");
std::cout << "-------------------------" << std::endl;
AMateria* tmp;
tmp = src->createMateria("ice");
std::cout << "-------------------------" << std::endl;
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
std::cout << "-------------------------" << std::endl; 
ICharacter* bob = new Character("bob");
std::cout << "-------------------------" << std::endl;
me->use(0, *bob);
std::cout << "-------------------------" << std::endl;
me->use(1, *bob);
std::cout << "-------------------------" << std::endl;
delete bob;
delete me;
delete src;
return 0;
}

// line 11 to 21 is the initialization of the MateriaSource object
// line 23 to 31 is the initialization of the Character object