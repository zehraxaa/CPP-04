/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:17:33 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/02/10 20:49:09 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain &other);
		Brain& operator=(const Brain &other);
		~Brain();

		const std::string& getIdeas(int index) const;
		std::string& getIdeas(int index);
		void setIdeas(std::string ideas[100]);
};

#endif