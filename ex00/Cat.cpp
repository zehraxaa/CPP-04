/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:41:42 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/02/08 12:42:04 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout<<"Cat default constructor called"<<std::endl;
	this->type = "";
}

Cat::Cat(std::string type)
{
	std::cout<<"Cat parameterized constructor called"<<std::endl;
	this->type = type;
}

Cat::Cat(const Cat &other)
{
	std::cout<<"Cat copy constructor called"<<std::endl;
	this->type = other.type;
}

Cat& Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

Cat::~Cat()
{
	std::cout<<"Cat destructor called"<<std::endl;
}

void Cat::makeSound()
{
	std::cout<<"Meow meow!!!"<<std::endl;
}