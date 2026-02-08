/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:00:21 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/02/08 16:11:21 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout<<"Brain default constructor called"<<std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout<<"Brain copy constructor called"<<std::endl;
	for (int i=0; i<100; i++)
		this->ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain &other)
{
	for (int i=0; i<100; i++)
		this->ideas[i] = other.ideas[i];
	return *this;
}

Brain::~Brain()
{
	std::cout<<"Brain destructor called"<<std::endl;
}
