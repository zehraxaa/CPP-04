/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:39:51 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/02/09 23:18:43 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout<<"Dog default constructor called"<<std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout<<"Dog copy constructor called"<<std::endl;
	this->type = other.type;
}

Dog& Dog::operator=(const Dog &other)
{
	std::cout<<"Dog copy asignment operator called"<<std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout<<"Dog destructor called"<<std::endl;
}

void Dog::makeSound() const
{
	std::cout<<"Woof woof!!!"<<std::endl;
}