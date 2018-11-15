#include <assert.h>
#include "list.h"
#include <cassert>

int main()
{
    Dish first, third;
    first.setName("Salad");
    first.setFats(3.2F);
    first.setCarbohydrates(15.7F);
    first.setAlimentaryFibers(41.0F);
    first.setOrganicAcids(25.4F);
    first.setProteins(8.3F);
    first.setWeight(250);
    Dish second(first);
    assert(second == first);
    second.setName("Soup");
    second.setFats(22.2F);
    second.setCarbohydrates(28.7F);
    second.setAlimentaryFibers(5.0F);
    second.setOrganicAcids(3.4F);
    second.setProteins(43.3F);
    second.setWeight(500);
    third.setName("Cake");
    third.setFats(24.2F);
    third.setCarbohydrates(3.7F);
    third.setAlimentaryFibers(18.0F);
    third.setOrganicAcids(25.4F);
    third.setProteins(8.3F);
    third.setWeight(250);
    List menu;
    menu.addNode(first);
    menu.addNode(second);
    menu.addNode(third);
    SetLunch today(first, second, third);
    menu.addNode(today);
    menu.writeInFile("AnotherOneMenu.dat");
    return 0;
}