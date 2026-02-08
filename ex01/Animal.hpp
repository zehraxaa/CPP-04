/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:19:01 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/02/08 14:58:05 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal(void);
		Animal(const Animal &other);
		Animal& operator=(const Animal &other);
		virtual ~Animal();
		
		std::string getType() const;;
		virtual void makeSound() const;
};

#endif