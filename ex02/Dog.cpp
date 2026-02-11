/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:39:51 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/02/11 13:27:57 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout<<"Dog default constructor called"<<std::endl;
	this->type = "Dog";
	this->idea = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout<<"Dog copy constructor called"<<std::endl;
	this->idea = new Brain(*other.idea);
}

Dog& Dog::operator=(const Dog &other)
{
	std::cout<<"Dog copy asignment operator called"<<std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete this->idea;
		this->idea = new Brain(*other.idea);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout<<"Dog destructor called"<<std::endl;
	delete this->idea;
}

void Dog::makeSound() const
{
	std::cout<<"Woof woof!!!"<<std::endl;
}

Brain* Dog::getIdeaAddress()
{
	return this->idea;
}

const Brain* Dog::getIdeaAddress() const
{
	return this->idea;
}

std::string &Dog::getIdea(int index)
{
    return this->idea->getIdeas(index);
}

const std::string &Dog::getIdea(int index) const
{
    return this->idea->getIdeas(index);
}