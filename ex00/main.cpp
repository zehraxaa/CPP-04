/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:21:33 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/02/13 00:11:56 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();

std::cout<<std::endl;

std::cout << meta->getType() << " " << std::endl;
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;

std::cout<<std::endl;

i->makeSound();
j->makeSound();
meta->makeSound();

std::cout<<std::endl;

delete i;
delete j;
delete meta;

std::cout<<std::endl;
std::cout<<std::endl;
std::cout<<"WRONG ANIMAL TEST:"<<std::endl;

const WrongAnimal* wct = new WrongCat();
std::cout<<std::endl;
std::cout<<wct->WrongAnimal::getType()<<std::endl;
std::cout<<std::endl;
wct->makeSound();
std::cout<<std::endl;
delete wct;

return 0;
}