/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:21:33 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/02/12 22:37:19 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// --------------------------------------------------------------------
    // TEST 1: ABSTRACT CLASS KONTROLÜ (Bu satırlar HATA vermelidir)
    // --------------------------------------------------------------------
    std::cout << "--- TEST 1: Abstract Class Check ---" << std::endl;
    
    // Aşağıdaki satırların yorumunu kaldırırsan derleyici HATA vermelidir.
    // Çünkü Animal soyut (abstract) bir sınıftır ve örneklendirilemez.
    
    // Animal test;                   // HATA: Variable type 'Animal' is an abstract class
    // Animal* test2 = new Animal();  // HATA: Allocating an object of abstract class type 'Animal'

    std::cout << "Animal sınıfından nesne oluşturulamıyor (Beklenen davranış)." << std::endl;
    std::cout << std::endl;

    // --------------------------------------------------------------------
    // TEST 2: POLİMORFİZM (Subject'in istediği temel test)
    // --------------------------------------------------------------------
    std::cout << "--- TEST 2: Polymorphism Check ---" << std::endl;
    
    // Nesne oluşturamasak da POINTER olarak kullanabiliriz.
    const Animal* j = new Dog();
    const Animal* i = new Cat();

	j->makeSound();
	i->makeSound();
	
	return 0;
}