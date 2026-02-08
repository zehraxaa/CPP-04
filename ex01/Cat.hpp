/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:41:03 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/02/08 15:59:18 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal
{
	private:
		Brain* idea;
	public:
		Cat(void);
		Cat(const Cat &other);
		Cat& operator=(const Cat &other);
		~Cat();

		void makeSound() const;
};

#endif