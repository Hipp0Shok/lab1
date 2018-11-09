#ifndef DISH_H
#define DISH_H
#include "base.h"
#include <iostream>
#include <string>


class Dish: public Base
{
public:
    Dish();
    Dish(const std::string &name, const float fats, const float proteins, const float carbohydrates, const float organicAcids, const float alimentaryFibers, const float weight);
    Dish(const Dish &);
    ~Dish();
    void changeFats(float const fats);
    void changeProteins(float const proteins);
    void changeCarbohydrates(float  const carbohydrates);
    void changeAlimentaryFibers(float const alimentaryFibers);
    void changeOrganicAcids(float  constorganicAcids);

};

#endif // DISH_H
