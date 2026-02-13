/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:46:05 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/02/13 00:20:17 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout<<"AMateria default constructor called"<<std::endl;
}

AMateria::AMateria(const AMateria &other)
{
	std::cout<<"AMateria copy constructor called"<<std::endl;
	this->type = other.type;
}

AMateria& AMateria::operator=(const AMateria &other)
{
	std::cout<<"AMateria copy assignment operator called"<<std::endl;
	(void)other;
	return *this;
}

AMateria::AMateria(std::string const & type)
{
	std::cout<<"AMateria parameterized constructor called"<<std::endl;
	this->type = type;
}

AMateria::~AMateria()
{
	std::cout<<"AMateria destructor called"<<std::endl;
}

const std::string& AMateria::getType() const
{
	return this->type;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}