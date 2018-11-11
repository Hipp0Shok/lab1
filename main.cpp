#include <iostream>
#include <string>
#include <assert.h>
#include <fstream>
#include "list.h"

int main()
{
    Dish ob0;
    ob0.setFats(57.3F);
    ob0.setWeight(25);
    std::cout << ob0.getEnergyValueOn100() << ob0.getEnergyValueTotal() << std::endl;
    Dish ob2(ob0);
    ob0.setName("First");
    ob2.setName("Second");
    ob2.setCarbohydrates(27.3F);
    Dish ob1("Bread", 12.2F, 15.3F, 2.2F, 3.1F, 17.0F, 25.1F);
    SetLunch complex;
    complex.setSoup(ob0);
    complex.setMainCourse(ob1);
    complex.setDessert(ob2);
    complex.setDay(TUESDAY);
    std::cout << ob0.getKind() << std::endl;
    std::cout << ob1.getKind()<< std::endl;
    std::cout << ob2.getKind() << std::endl;
    std::cout << complex.getKind() << std::endl;
    List foo;
    foo.addNode(&ob2);
    foo.addNode(&complex);
    //foo.writeInFile("TestFile2.dat");
    List bar;
    bar.readFromFile("TestFile2.dat");
    assert(foo == bar);
    return 0;
}