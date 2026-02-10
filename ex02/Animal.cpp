/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:25:09 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/02/11 00:56:25 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout<<"Animal default constructor called"<<std::endl;
	this->type = "Animal";
}

Animal::Animal(const Animal &other)
{
	std::cout<<"Animal copy constructor called"<<std::endl;
	this->type = other.type;
}

Animal& Animal::operator=(const Animal &other)
{
	std::cout<<"Animal copy asignment operator called"<<std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

Animal::~Animal()
{
	std::cout<<"Animal destructor called"<<std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}


