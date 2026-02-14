/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:14:04 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/02/14 00:44:22 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout<<"MateriaSource default constructor called"<<std::endl;
    for (int i = 0; i < 4; i++)
        this->templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    std::cout<<"MateriaSource copy constructor called"<<std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (other.templates[i])
            this->templates[i] = other.templates[i]->clone();
        else
            this->templates[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
    std::cout<<"MateriaSource assignment operator called"<<std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->templates[i])
                delete this->templates[i];
        }
        for (int i = 0; i < 4; i++)
        {
            if (other.templates[i])
                this->templates[i] = other.templates[i]->clone();
            else
                this->templates[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    std::cout<<"MateriaSource destructor called"<<std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->templates[i])
            delete this->templates[i];
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (this->templates[i] == NULL)
        {
            this->templates[i] = m; // Şablonu kaydet. static kısmı yani pointer adresi olan yeri tutuyor.
            //nesnenin kendisini tutmuyor yani. işaretçi. aşağıda clone yapınca nesne koyuyor yerine
            return;
        }
    }
    // Yer yoksa gelen materia silinmeli mi? Genelde hayır, çağıranın sorumluluğunda.
    // Ama burada pointer'ı saklayamadığımız için memory leak olmaması adına main'de dikkat edilmeli.
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->templates[i] && this->templates[i]->getType() == type)
        {
            return this->templates[i]->clone();
        }
    }
    return 0;
}