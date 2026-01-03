#include <iostream>

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria(std::string const &type);
        std::string const & getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
        //canonical form 
};