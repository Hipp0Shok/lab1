#include "dish.h"

Dish::Dish()
    :  Base()
{
}
Dish::Dish(std::string const  &name, float const fats, float  const proteins, float  const carbohydrates,
           float  const organicAcids, float  const alimentaryFibers, float  const weight)
    :  Base(name, fats, proteins, carbohydrates, organicAcids, alimentaryFibers, weight)
{
}
Dish::Dish(const Dish &existing):
    Base(existing)
{

}
Dish::~Dish()
{

}

void Dish::changeFats(float fats)
{
    if(fats >= 0 && fats <= 100)
    {
        _fats = fats;
    }
}

void Dish::changeProteins(const float proteins)
{
    if(proteins >= 0 && proteins <= 100)
    {
        _proteins = proteins;
    }
}
void Dish::changeAlimentaryFibers(const float alimentaryFibers)
{
    if(alimentaryFibers >= 0 && alimentaryFibers <= 100)
    {
        _alimentaryFibers = alimentaryFibers;
    }
}
void Dish::changeCarbohydrates(const float carbohydrates)
{
    if(carbohydrates >= 0 && carbohydrates <= 100)
    {
        _carbohydrates = carbohydrates;
    }
}
void Dish::changeOrganicAcids(const float organicAcids)
{
    if(organicAcids >= 0 && organicAcids <= 100)
    {
        _organicAcids = organicAcids;
    }
}
