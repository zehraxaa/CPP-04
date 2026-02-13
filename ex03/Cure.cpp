/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 22:45:30 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/02/13 00:24:08 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout<<"Cure default constructor called"<<std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other)
{
    std::cout<<"Cure copy constructor called"<<std::endl;
    this->type = other.type;
}

Cure& Cure::operator=(const Cure &other)
{
    std::cout<<"Cure assignment operator called"<<std::endl;
    if (this != &other)
        AMateria::operator=(other);
    return *this;
}

Cure::~Cure()
{
    std::cout<<"Cure destructor called"<<std::endl;
}

AMateria* Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}