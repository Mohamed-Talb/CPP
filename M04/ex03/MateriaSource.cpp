#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0;i < 4; i++)
    {
        LMaterias[i] = NULL;
    }
    // std::cout << "MateriaSource Default Constructor Called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    for (int i = 0; i < 4; i++)
    {
        if ( LMaterias[i])
            delete  LMaterias[i];
        if (other.LMaterias[i])
            LMaterias[i] = other.LMaterias[i]->clone();
        else
            LMaterias[i] = NULL;
    }
    // std::cout << "MateriaSource Copy Constructor Called" << std::endl;
}

const MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if ( LMaterias[i])
                delete  LMaterias[i];
            if (other.LMaterias[i])
                LMaterias[i] = other.LMaterias[i]->clone();
            else
                LMaterias[i] = NULL;
        }
    }
    // std::cout << "MateriaSource Copy Assignment Operator Called" << std::endl;
    return *this;
}


MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (LMaterias[i])
            delete LMaterias[i];
    }
    // std::cout << "MateriaSource Destructor Called" << std::endl;
}


void MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if(LMaterias[i] == NULL)
        {
            LMaterias[i] = m->clone();
            delete m;
            return ;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if(LMaterias[i] && LMaterias[i]->getType() == type)
            return LMaterias[i]->clone();
    }
    return NULL;
}