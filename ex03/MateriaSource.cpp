/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:14:04 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/02/11 16:12:25 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        this->templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
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
    for (int i = 0; i < 4; i++)
    {
        if (this->templates[i])
            delete this->templates[i];
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m) return;
    for (int i = 0; i < 4; i++)
    {
        if (this->templates[i] == NULL)
        {
            this->templates[i] = m; // Şablonu kaydet
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
            return this->templates[i]->clone(); // Kopyasını üretip ver
        }
    }
    return 0; // Bulamazsa 0 (NULL) döndür
}