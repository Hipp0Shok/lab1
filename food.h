#ifndef FOOD_H
#define FOOD_H
#include "iostream"
#include "string.h"


class Food
{
public:
    Food();
    Food(std::string const &, float const &);
    Food(Food const &);
    virtual ~Food() = 0;
    virtual float getEnergyValue() const;
    virtual std::string getName() const { return _name;}
    virtual void setName(std::string const &);
    virtual float getWeight() const { return _weight;}
    virtual void setWeight(float const &);
protected:
    std::string _name;
    float _weight;
};

#endif // FOOD_H