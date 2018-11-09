#include <iostream>
#include "dish.h"
#include "list.h"
#include <string>
#include <assert.h>
#include <fstream>
#include "setlunch.h"
#include "base.h"

void dishOutput(Base existing)
{
    std::cout << "Name: "<< existing.getName() << std::endl;
    std::cout << "Weight: "<< existing.getWeight() << " grams" << std::endl;
    std::cout << "Fats: "<< existing.getFats() << " in 100 grams" << std::endl;
    std::cout << "Proteins: "<< existing.getProteins() << " in 100 grams" << std::endl;
    std::cout << "Carbohydrates: "<< existing.getCarbohydrates() << " in 100 grams" << std::endl;
    std::cout << "Organic Acids: "<< existing.getOrganicAcids() << " in 100 grams" << std::endl;
    std::cout << "Alimentary Fibers: "<< existing.getAlimentaryFibers() << " in 100 grams" << std::endl;
    std::cout << "Energy Value: "<< existing.getEnergyValueOn100() << " kcals in 100 grams" << std::endl;
    std::cout << "              "<< existing.getEnergyValueTotal() <<
                 " kcals in " << existing.getWeight() << " grams"<< std::endl;
    std::cout << "___________________________________________________________" << std::endl;
}

void output(List &existing)
{
    List::Iterator iterator;
    int i = 1;
    for(iterator = existing.begin(); iterator != nullptr; iterator++, i++)
    {
        std::cout << i << std::endl;
        dishOutput(*iterator);
        std::cout << "___________________________________________________________" << std::endl;
    }

}

int main()
{
    Dish ob0, ob1, ob2, ob3;
    List firstList;
    ob0.setName("FIRST");
    ob0.changeFats(40.2F);
    ob0.setWeight(258.3F);
    ob0.changeCarbohydrates(20.4F);
    ob0.setWeight(153.2F);
    ob1.setName("SECOND");
    ob1.changeFats(80.2F);
    ob2.setName("THIRD");
    ob2.changeFats(20.2F);
    ob2.changeOrganicAcids(1.7F);
    ob2.changeProteins(25.13F);
    ob2.changeAlimentaryFibers(2.2F);
    ob3.setName("FORTH");
    ob3.changeFats(70.0F);
    int previousLength = firstList.getLength();
    firstList.addNode(ob0);
    assert(firstList.getLength() == previousLength + 1);
    firstList.addNode(ob1);
    firstList.addNode(ob2);
    firstList.addNode(ob3);
    std::cout<<"First List: " << std::endl;
    output(firstList);
    List secondList(firstList);
    assert(firstList == secondList);
    List::Iterator iterator;
    iterator = firstList.begin();
    previousLength = firstList.getLength();
    firstList.deleteNode(iterator);
    std::cout<<"Changed list: " << std::endl;
    output(firstList);
    assert(firstList.getLength() == previousLength - 1);
    assert(firstList != secondList);
    firstList.deleteList();
    assert(firstList.getLength() == 0);
    std::cout << "Second List: " << std::endl;
    output(secondList);
    secondList.writeInFile("FileForTest.dat");
    firstList.readFromFile("FileForTest.dat");
    assert(secondList == firstList);
    Base found;
    found = secondList.findDish(750.0F);
    std::cout << "Finded Dish: " << std::endl;
    dishOutput(found);
    std::cout<<"OK!"<<std::endl;
    Dish ob10(ob1);
    ob10.getEnergyValueOn100();
    //Лабораторная работа номер 3
    return 0;
}