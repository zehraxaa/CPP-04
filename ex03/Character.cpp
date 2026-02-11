/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:13:35 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/02/11 16:11:33 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("Default")
{
    // std::cout << "Character default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

// Parametreli Constructor (Subject isteği)
Character::Character(std::string const & name) : name(name)
{
    // std::cout << "Character parameterized constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

// Copy Constructor
Character::Character(const Character &other) : name(other.name)
{
    // std::cout << "Character copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (other.inventory[i])
            this->inventory[i] = other.inventory[i]->clone(); // Deep Copy
        else
            this->inventory[i] = NULL;
    }
}

// Assignment Operator
Character& Character::operator=(const Character &other)
{
    // std::cout << "Character assignment operator called" << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        
        // 1. Mevcut eşyaları sil (Memory Leak önlemi)
        for (int i = 0; i < 4; i++)
        {
            if (this->inventory[i])
                delete this->inventory[i];
        }

        // 2. Yeni eşyaları kopyala (Deep Copy)
        for (int i = 0; i < 4; i++)
        {
            if (other.inventory[i])
                this->inventory[i] = other.inventory[i]->clone();
            else
                this->inventory[i] = NULL;
        }
    }
    return *this;
}

// Destructor
Character::~Character()
{
    // std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i])
            delete this->inventory[i];
    }
}

std::string const & Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria* m)
{
    if (!m) return;
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i] == NULL)
        {
            this->inventory[i] = m;
            // std::cout << "Equipped " << m->getType() << " to slot " << i << std::endl;
            return;
        }
    }
    // Envanter doluysa eşya takılamaz (burada silmiyoruz, çağıranın sorumluluğunda)
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
    {
        this->inventory[idx] = NULL; // Sadece pointer'ı düşür, silme!
        // std::cout << "Unequipped slot " << idx << std::endl;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && this->inventory[idx])
    {
        this->inventory[idx]->use(target);
    }
}
