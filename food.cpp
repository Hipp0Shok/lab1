#include "food.h"
#include "iostream"
#include "string.h"

Food::Food():
    _name("Water"),
    _weight(0.0F)
{

}


Food::Food(std::string const &name, float const &weight):
    _name(!name.empty() ? name : "Water"),
    _weight(weight >= 0 ? weight : 0.0F)
{
}

Food::Food(Food const &existing):
    _name(existing._name),
    _weight(existing._weight)
{
}

float Food::getEnergyValue() const
{
    return 0.0F;
}

void Food::setName(std::string const &name)
{
    if(!name.empty())
    {
        _name = name;
    }
}

void Food::setWeight(float const &weight)
{
    if(weight >= 0)
    {
        _weight = weight;
    }
}
