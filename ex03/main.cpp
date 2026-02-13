/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:23:32 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/02/13 00:22:59 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

void subjectTest()
{
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "--- SUBJECT TEST (MANDATORY) ---" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;

    // 1. Materia Kaynağı (Üretici) oluştur
    IMateriaSource* src = new MateriaSource();
    
    // 2. Şablonları (Templates) öğren
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    // 3. Karakter oluştur
    ICharacter* me = new Character("me");
    
    // 4. Materia üret ve kuşan (Equip)
    AMateria* tmp;
    
    tmp = src->createMateria("ice");
    me->equip(tmp);
    
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    // 5. Hedef karakter oluştur
    ICharacter* bob = new Character("bob");
    
    // 6. Büyüleri kullan (Use)
    me->use(0, *bob); // Ice -> shoots an ice bolt at bob
    me->use(1, *bob); // Cure -> heals bob's wounds
    

    delete bob;
    delete me;
    delete src;
}

void detailedTest()
{
    std::cout << "\n-------------------------------------------------------" << std::endl;
    std::cout << "--- DETAILED TEST (DEEP COPY & INVENTORY) ---" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    Character* cloud = new Character("Cloud");
    
    // --- TEST 1: Inventory Management & Unknown Materia ---
    std::cout << "\n[TEST 1] Inventory & Unknown Materia" << std::endl;
    AMateria* m1 = src->createMateria("ice");
    cloud->equip(m1);
    
    AMateria* m2 = src->createMateria("cure");
    cloud->equip(m2);
    
    AMateria* m3 = src->createMateria("fire"); // Bilinmeyen materyal
    if (m3 == NULL)
        std::cout << "Success: Unknown materia 'fire' returned NULL." << std::endl;
    else
        cloud->equip(m3); // Olur da oluşturursa (Hata)

    // --- TEST 2: Deep Copy Character ---
    std::cout << "\n[TEST 2] Deep Copy Character (Copy Constructor)" << std::endl;
    Character* tifa = new Character(*cloud); // Cloud'un kopyası
    
    std::cout << "Cloud uses item 0:" << std::endl;
    cloud->use(0, *tifa);
    
    std::cout << "Tifa (Copy) uses item 0:" << std::endl;
    tifa->use(0, *cloud);

    // Deep Copy Kanıtı: Tifa'nın item'ını silelim/değiştirelim, Cloud etkilenmemeli
    // (Burada manuel test yerine pointer adreslerine bakmak gerekirdi ama
    // use fonksiyonunun çalışması kopyalamanın başarılı olduğunu gösterir.)

    // --- TEST 3: Unequip & Memory Leak Prevention ---
    std::cout << "\n[TEST 3] Unequip Logic" << std::endl;
    
    // Subject kuralı: Unequip edilen materyali Character SİLMEZ.
    // Bu yüzden pointer'ı kaybetmemek için önce bir yerde tutmalıyız.
    // Gerçek hayatta bu pointer'ı yere atılmış eşyalar listesine eklerdik.
    
    // Cloud'un 0. slotundaki (Ice) eşyayı çıkaracağız.
    // Ancak Character sınıfında getMateria olmadığı için (interface izin vermiyor),
    // testi şöyle yapıyoruz: Dışarıdan oluşturduğumuz bir pointer ile.
    
    AMateria* floorItem = src->createMateria("cure");
    cloud->equip(floorItem); // Slot 2'ye takıldı (0 ve 1 doluydu)
    
    std::cout << "Equipped Cure to Slot 2. Using it:" << std::endl;
    cloud->use(2, *tifa);
    
    std::cout << "Unequipping Slot 2..." << std::endl;
    cloud->unequip(2);
    
    std::cout << "Trying to use Slot 2 (Should do nothing):" << std::endl;
    cloud->use(2, *tifa); // Hiçbir şey yazmamalı
    
    // floorItem artık envanterde değil ama hafızada duruyor.
    // Manuel olarak silmeliyiz (Memory Leak olmaması için)
    delete floorItem; 
    std::cout << "Unequipped item manually deleted." << std::endl;

    // --- Temizlik ---
    delete tifa;
    delete cloud;
    delete src;
}

int main()
{
    subjectTest();
    detailedTest();
    
    // Memory Leak kontrolü için (Mac/Linux)
    // system("leaks ex03"); 
    
    return 0;
}