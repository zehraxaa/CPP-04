/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:21:33 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/02/11 01:00:31 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	//const Animal* meta = new Animal();
	//Animal test;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	j->makeSound();
	i->makeSound();
	
	return 0;
}