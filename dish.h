#ifndef DISH_H
#define DISH_H
#include "D:\study\info\lab1\food.h"
#include <iostream>
#include <string>


class Dish
{
public:
    Dish();
    Dish(const std::string &name, const float fats, const float proteins, const float carbohydrates, const float organicAcids, const float alimentaryFibers, const float weight);
    Dish(const Dish &);
    ~Dish();
    float getFats() const;
    float getProteins() const;
    float getCarbohydrates() const;
    float getOrganicAcids() const;
    float getAlimentaryFibers() const;
    float getEnergyValueOn100() const;
    float getEnergyValueTotal() const;
    void changeFats(float const fats);
    void changeProteins(float const proteins);
    void changeCarbohydrates(float  const carbohydrates);
    void changeAlimentaryFibers(float const alimentaryFibers);
    void changeOrganicAcids(float  constorganicAcids);
    bool operator == (Dish const &);
    bool operator != (Dish const &);
private:
    float _fats, _proteins, _carbohydrates, _organicAcids, _alimentaryFibers;
};

#endif // DISH_H
