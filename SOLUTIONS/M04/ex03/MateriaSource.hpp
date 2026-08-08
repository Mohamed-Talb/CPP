#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *LMaterias[4];
    public:
    MateriaSource();
    ~MateriaSource();
    MateriaSource(const MateriaSource &MS);
    const MateriaSource &operator=(const MateriaSource &MS);
    
    void learnMateria(AMateria *m);
    AMateria* createMateria(std::string const & type);
};

#endif