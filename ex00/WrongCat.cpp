/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:31:07 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/02/13 00:13:12 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

WrongCat::WrongCat(void)
{
	std::cout<<"WrongCat default constructor called"<<std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout<<"WrongCat copy constructor called"<<std::endl;
	this->type = other.type;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
	std::cout<<"WrongCat copy asignment operator called"<<std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout<<"WrongCat destructor called"<<std::endl;
}

void WrongCat::makeSound() const
{
	std::cout<<"WrongCat Meow meow!!!"<<std::endl;
}
