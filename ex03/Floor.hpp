/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 23:55:00 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/02/14 23:55:03 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_HPP
# define FLOOR_HPP

#include "AMateria.hpp"

class Floor
{
    private:
        struct Node {
            AMateria* m;
            Node* next;
        };
        Node* head;

    public:
        Floor();
        Floor(const Floor &other);
        Floor& operator=(const Floor &other);
        ~Floor();

        void dropMateria(AMateria* m);
};

#endif