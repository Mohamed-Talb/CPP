#include <iostream>

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria(std::string const & type);
        std::string const & getType() const;
        virtual AMateria* clone() const; // implemet return new cure()
        virtual void use(ICharacter& target);// messgaes
        //canonical form 
};