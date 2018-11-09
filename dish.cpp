#include "dish.h"

Dish::Dish()
    :   _name("Water"),
    _fats(0),
    _proteins(0),
    _carbohydrates(0),
    _organicAcids(0),
    _alimentaryFibers(0),
    _weight(0)
{
}
Dish::Dish(std::string const  &name, float const fats, float  const proteins, float  const carbohydrates,
           float  const organicAcids, float  const alimentaryFibers, float  const weight)
    :  _name(!name.empty() ? name : "Water"),
    _fats(fats > 0 && fats <= 100 ? fats : 0),
    _proteins(proteins > 0 && proteins <= 100 ? proteins : 0),
    _carbohydrates(carbohydrates > 0 && carbohydrates <= 100 ? carbohydrates : 0),
    _organicAcids(organicAcids > 0 && organicAcids <= 100 ? organicAcids : 0),
    _alimentaryFibers(alimentaryFibers > 0 && alimentaryFibers <= 100 ? alimentaryFibers : 0),
    _weight(weight > 0 ? weight : 1)
{
}
Dish::Dish(const Dish &) = default;
Dish::~Dish() = default;
float Dish::getFats() const
{
    return _fats;
}
float Dish::getProteins() const
{
    return _proteins;
}
float Dish::getCarbohydrates() const
{
    return _carbohydrates;
}
float Dish::getOrganicAcids() const
{
    return _organicAcids;
}
float Dish::getAlimentaryFibers() const
{
    return _alimentaryFibers;
}
float Dish::getEnergyValueOn100() const
{
    return 9.29F*_fats + 4.1F*_proteins + 4.1F*_carbohydrates +
            2.2F*_organicAcids + 1.9F*_alimentaryFibers;
}
std::string Dish::getName() const
{
    return _name;
}
void Dish::changeFats(float fats)
{
    if(fats >= 0 && fats <= 100)
    {
        _fats = fats;
    }
}
void Dish::changeName(const std::string &name)
{
    if(!name.empty())
    {
        _name = name;
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

float Dish::getWeight() const
{
    return _weight;
}

void Dish::changeWeight(float weight)
{
    if(weight >= 0)
    {
        _weight = weight;
    }
}

float Dish::getEnergyValueTotal() const
{
    return getEnergyValueOn100()*_weight/100;
}

bool Dish::operator == (Dish const & existing)
{
    return( this->_name == existing._name &&
            this->_fats == existing._fats &&
            this->_proteins == existing._proteins &&
            this->_carbohydrates == existing._carbohydrates &&
            this->_organicAcids == existing._organicAcids &&
            this->_alimentaryFibers == existing._alimentaryFibers &&
            this->_weight == existing._weight);
}

bool Dish::operator!=(Dish const &existing)
{
    return !(*this == existing);
}