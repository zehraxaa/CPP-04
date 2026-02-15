/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:23:24 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/02/15 12:12:05 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice(const Ice &other);
        Ice& operator=(const Ice &other);
        virtual ~Ice();

        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};

#endif