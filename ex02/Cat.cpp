/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:41:42 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/02/10 23:44:03 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout<<"Cat default constructor called"<<std::endl;
	this->type = "Cat";
	idea = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout<<"Cat copy constructor called"<<std::endl;
	this->idea = new Brain(*other.idea);
}

Cat& Cat::operator=(const Cat &other)
{
	std::cout<<"Cat copy asignment operator called"<<std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete this->idea;
		this->idea = new Brain(*other.idea);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout<<"Cat destructor called"<<std::endl;
	delete idea;
}

void Cat::makeSound() const
{
	std::cout<<"Meow meow!!!"<<std::endl;
}

Brain* Cat::getIdeaAddress()
{
    return this->idea;
}

const Brain* Cat::getIdeaAddress() const
{
    return this->idea;
}

std::string &Cat::getIdea(int index)
{
    return this->idea->getIdeas(index);
}

const std::string &Cat::getIdea(int index) const
{
    return this->idea->getIdeas(index);
}
