/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:21:33 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/02/15 01:04:56 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "--- Test 1: Abstract Class Check ---" << std::endl;
    
    // Animal test;
    // Animal* test2 = new Animal();

    std::cout << "--- Test 2: Polymorphism Check ---" << std::endl;
   
    const Animal* j = new Dog();
    const Animal* i = new Cat();

	j->makeSound();
	i->makeSound();
	
	return 0;
}