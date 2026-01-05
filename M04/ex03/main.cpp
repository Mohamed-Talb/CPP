#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    
    AMateria* tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    
    me->use(0, *bob);
    me->use(1, *bob);
    
    delete bob;
    delete me;
    delete src;


    // MY TESTS
    // AMateria *Ftmp1;
    // AMateria *Ftmp2;

    // IMateriaSource *Source = new MateriaSource();
    // Source->learnMateria(new Ice());
    // Source->learnMateria(new Cure());

    // AMateria *l3afya = Source->createMateria("ice");
    // AMateria *telj = Source->createMateria("Cure");
    
    // ICharacter *Player1 = new Character("SOUL"); 
    // ICharacter *Player2 = new Character("PHILO"); 
    // ICharacter *Player3 = new Character("DEXTER");

    // Player1->equip(l3afya);
    // Player1->equip(telj);
    // Player1->unequip(0);
    // // Ftmp1 = l3afya;
    // // Ftmp2 = telj;
    // // Player1->unequip(0);
    // // Player1->unequip(1);
    
    // // delete Ftmp1;
    // // delete Ftmp2;

    // Player2->equip(l3afya);
    // Player2->unequip(0);
    // Player3->equip(l3afya);

    // delete Player1;
    // delete Player2;
    // delete Player3;
    // delete Source;
    return 0;
}
