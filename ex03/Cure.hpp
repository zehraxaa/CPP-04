/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:23:19 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/02/15 12:11:54 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
    private:
        std::string type;
    public:
        Cure();
		Cure(const Cure &other);
		Cure& operator=(const Cure &other);
		virtual ~Cure();
		
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);


};

#endif