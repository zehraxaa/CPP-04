/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:36:34 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/02/10 23:42:56 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal
{
	private:
		Brain* idea;
	public:
		Dog(void);
		Dog(const Dog &other);
		Dog& operator=(const Dog &other);
		~Dog();
		
		void makeSound() const;
		Brain*       getIdeaAddress();              // non-const Dog için
		const Brain* getIdeaAddress() const;        // const Dog için
		std::string &getIdea(int index);           // fikri okumak/değiştirmek için
		const std::string &getIdea(int index) const; // sadece fikri okumak için
};

#endif