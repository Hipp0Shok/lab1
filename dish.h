#ifndef DISH_H
#define DISH_H
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
    float getWeight() const;
    float getEnergyValueTotal() const;
    std::string getName() const;
    void changeFats(float const fats);
    void changeProteins(float const proteins);
    void changeName(const std::string &name);
    void changeCarbohydrates(float  const carbohydrates);
    void changeAlimentaryFibers(float const alimentaryFibers);
    void changeOrganicAcids(float  constorganicAcids);
    void changeWeight(float  const weight);
    bool operator == (Dish const &);
    bool operator != (Dish const &);
private:
    std::string _name;
    float _fats, _proteins, _carbohydrates, _organicAcids, _alimentaryFibers, _weight;
};

#endif // DISH_H
