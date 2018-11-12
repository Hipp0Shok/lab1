#include "dish.h"

Dish::Dish():
    Base (),
    _name("Water")
{
    _kind = DISH;
}

Dish::Dish(std::string const  &name, float const &fats, float  const &proteins, float  const &carbohydrates,
           float  const &organicAcids, float  const &alimentaryFibers, float  const &weight)
    :  Base(fats, proteins, carbohydrates, organicAcids, alimentaryFibers, weight),
      _name(!name.empty() ? name : "Water")
{
    _kind = DISH;
}

Dish::Dish(Dish const &existing):
    Base(existing),
    _name(existing._name)
{
    _kind = DISH;
}

Dish::~Dish()
{

}

void Dish::setFats(float const &fats)
{
    if(fats >= 0 && fats <= 100)
    {
        _fats = fats;
    }
}

void Dish::setProteins(const float &proteins)
{
    if(proteins >= 0 && proteins <= 100)
    {
        _proteins = proteins;
    }
}

void Dish::setAlimentaryFibers(const float &alimentaryFibers)
{
    if(alimentaryFibers >= 0 && alimentaryFibers <= 100)
    {
        _alimentaryFibers = alimentaryFibers;
    }
}
void Dish::setCarbohydrates(const float &carbohydrates)
{
    if(carbohydrates >= 0 && carbohydrates <= 100)
    {
        _carbohydrates = carbohydrates;
    }
}
void Dish::setOrganicAcids(const float &organicAcids)
{
    if(organicAcids >= 0 && organicAcids <= 100)
    {
        _organicAcids = organicAcids;
    }
}

void Dish::setWeight(float const &weight)
{
    if(weight >= 0)
    {
        _weight = weight;
    }
}

void Dish::setName(std::string const &name)
{
    if(!name.empty())
    {
        _name = name;
    }
}

bool Dish::operator == (Dish const &existing) const
{
    if(Base::operator==(existing) && _name == existing._name)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Dish::operator!=(Dish const &existing) const
{
    if(Base::operator!=(existing) || _name != existing._name)
    {
        return true;
    }
    else
    {
        return false;
    }
}

float Dish::getEnergyValueOn100() const
{
    return getEnergyValueTotal()*100/_weight;
}

Base &Dish::operator =(const Base &existing)
{
    *this = operator=(*dynamic_cast<const Dish*>(&existing));
    return *this;
}

void Dish::write(std::ofstream &file)
{
    Base::write(file);
    int length = static_cast<int>(_name.length()) + 1;
    file.write(reinterpret_cast<char*>(&length), sizeof (int));
    file.write(_name.c_str(), length);
}

void Dish::read(std::ifstream &file)
{
    Base::read(file);
    int length;
    char buffer[50];
    file.read(reinterpret_cast<char*>(&length), sizeof (int));
    file.read(reinterpret_cast<char*>(buffer), length);
    _name = buffer;
}

Dish& Dish::operator = (Dish const &existing)
{
    if(this == &existing)
    {
        return *this;
    }
    else
    {
        Base::operator=(existing);
        _name = existing._name;
        return *this;
    }
}