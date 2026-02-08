/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:39:51 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/02/08 12:40:49 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout<<"Dog default constructor called"<<std::endl;
	this->type = "";
}

Dog::Dog(std::string type)
{
	std::cout<<"Dog parameterized constructor called"<<std::endl;
	this->type = type;
}

Dog::Dog(const Dog &other)
{
	std::cout<<"Dog copy constructor called"<<std::endl;
	this->type = other.type;
}

Dog& Dog::operator=(const Dog &other)
{
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

void Dog::makeSound()
{
	std::cout<<"Woof woof!!!"<<std::endl;
}