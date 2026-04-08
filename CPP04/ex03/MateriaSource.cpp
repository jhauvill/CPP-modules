#include "MateriaSource.hpp"


MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	for (int i = 0; i < 4; i++)
		this->_materias[i] = src._materias[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &second)
{
	if (this != &second)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_materias[i])
			{
				delete this->_materias[i];
				this->_materias[i] = NULL;
			}
			this->_materias[i] = second._materias[i];
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i])
		{
			delete this->_materias[i];
			this->_materias[i] = NULL;
		}
	}
}

void MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_materias[i])
		{
			this->_materias[i] = materia;
			return ;
		}
	}
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < 4; i++)
	{
		if ( this->_materias[i] && this->_materias[i]->getType() == type)
			return(this->_materias[i]->clone());
	}
	return NULL;
}
