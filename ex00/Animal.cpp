/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:25:09 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/02/08 12:43:58 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout<<"Animal default constructor called"<<std::endl;
	this->type = "";
}

Animal::Animal(std::string type)
{
	std::cout<<"Animal parameterized constructor called"<<std::endl;
	this->type = type;
}

Animal::Animal(const Animal &other)
{
	std::cout<<"Animal copy constructor called"<<std::endl;
	this->type = other.type;
}

Animal& Animal::operator=(const Animal &other)
{
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

std::string Animal::getType()
{
	if (this->type != "")
		return this->type;
	return " ";
}

void Animal::setType(std::string type)
{
	this->type = type;
}

void Animal::makeSound()
{
	std::cout<<"???"<<std::endl;	
}
