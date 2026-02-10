/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:21:33 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/02/11 00:42:05 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout<<"Test 1 --- Creating 100 Animal Objects ---"<<std::endl<<std::endl;

	Animal* animals[100];
	
	std::cout<<"Dog objects creating:"<<std::endl;
	for (int i=0; i<50; i++)
		animals[i] = new Dog();

	std::cout<<std::endl<<"Cat objects creating:"<<std::endl;
	for (int i=50; i<100; i++)
		animals[i] = new Cat();

	std::cout<<std::endl<<"Sounds of animal objects:"<<std::endl;
	for (int i=0; i<100; i++)
		animals[i]->makeSound();
	
	std::cout<<std::endl<<"Deleting animal objects:"<<std::endl;
	for (int i=0; i<100; i++)
		delete animals[i];
	
	std::cout<<std::endl<<"Test 2 --- The Test Given in Subject ---"<<std::endl<<std::endl;
	
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	delete j;
	delete i;

	std::cout<<std::endl<<"Test 3 --- Dog Deep Copy Constructor Test ---"<<std::endl<<std::endl;
	
	Dog a;
	a.getIdea(0) = "I am a dog";
	Dog b(a);
	
	std::cout<<std::endl<<"Dog1 Idea address: "<<a.getIdeaAddress()<<std::endl;
	std::cout<<"Dog2 Idea address: "<<b.getIdeaAddress()<<std::endl<<std::endl;
	
	std::cout<<"Dog1 Idea: "<<a.getIdea(0)<<std::endl;
	std::cout<<"Dog2 Idea: "<<b.getIdea(0)<<std::endl<<std::endl;
	a.getIdea(0) = "I am a happy dog!";
	std::cout<<"Dog1 Idea: "<<a.getIdea(0)<<std::endl;
	std::cout<<"Dog2 Idea: "<<b.getIdea(0)<<std::endl<<std::endl;
	b.getIdea(0) = "I love running";
	std::cout<<"Dog1 Idea: "<<a.getIdea(0)<<std::endl;
	std::cout<<"Dog2 Idea: "<<b.getIdea(0)<<std::endl;

	std::cout<<std::endl<<"Test 4 --- Cat Deep Copy Assignment Operator Test ---"<<std::endl<<std::endl;

	Cat c;
	Cat d;

	c.getIdea(0) = "I am hiding from the dogs";
	d = c;
	std::cout<<std::endl<<"Cat1 idea address: "<<c.getIdeaAddress()<<std::endl;
	std::cout<<"Cat2 idea address: "<<d.getIdeaAddress()<<std::endl<<std::endl;

	std::cout<<"Cat1 idea: "<<c.getIdea(0)<<std::endl;
	std::cout<<"Cat2 idea: "<<d.getIdea(0)<<std::endl<<std::endl;
	
	d.getIdea(0) = "Don't be afraid, I am protecting you";
	std::cout<<"Cat1 idea: "<<c.getIdea(0)<<std::endl;
	std::cout<<"Cat2 idea: "<<d.getIdea(0)<<std::endl<<std::endl;
	
	return 0;
}