/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 23:55:24 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/02/14 23:55:58 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Floor.hpp"

Floor::Floor() : head(NULL) {}

Floor::Floor(const Floor &other) : head(NULL)
{
    Node* current = other.head;
    while (current)
    {
        this->dropMateria(current->m->clone());
        current = current->next;
    }
}

Floor& Floor::operator=(const Floor &other)
{
    if (this != &other)
    {
        Node* current = this->head;
        while (current)
        {
            Node* next = current->next;
            delete current->m;
            delete current;
            current = next;
        }
        this->head = NULL;

        current = other.head;
        while (current)
        {
            this->dropMateria(current->m->clone());
            current = current->next;
        }
    }
    return *this;
}

Floor::~Floor()
{
    Node* current = this->head;
    while (current)
    {
        Node* next = current->next;
        delete current->m;
        delete current;
        current = next;
    }
}

void Floor::dropMateria(AMateria* m)
{
    if (!m) return;
    Node* newNode = new Node;
    newNode->m = m;
    newNode->next = this->head;
    this->head = newNode;
}