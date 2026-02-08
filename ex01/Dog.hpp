/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:36:34 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/02/08 15:59:12 by aaydogdu         ###   ########.fr       */
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
};

#endif