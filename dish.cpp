#include "dish.h"

Dish::Dish():
        _name("Water"),
        _fats(0.0F),
        _proteins(0.0F),
        _carbohydrates(0.0F),
        _organicAcids(0.0F),
        _alimentaryFibers(0.0F),
        _weight(0.0F)
{
}

Dish::Dish(QString const  &name, float const &fats, float  const &proteins, float  const &carbohydrates,
           float  const &organicAcids, float  const &alimentaryFibers, float  const &weight):
    _name(!name.isEmpty() ? name : "Water"),
    _fats(fats > 0 && fats <= 100 ? fats : 0),
    _proteins(proteins > 0 && proteins <= 100 ? proteins : 0),
    _carbohydrates(carbohydrates > 0 && carbohydrates <= 100 ? carbohydrates : 0),
    _organicAcids(organicAcids > 0 && organicAcids <= 100 ? organicAcids : 0),
    _alimentaryFibers(alimentaryFibers > 0 && alimentaryFibers <= 100 ? alimentaryFibers : 0),
    _weight(weight > 0 ? weight : 1)
{
}

Dish::Dish(Dish const &existing):
    _name(existing._name),
    _fats(existing._fats),
    _proteins(existing._proteins),
    _carbohydrates(existing._carbohydrates),
    _organicAcids(existing._organicAcids),
    _alimentaryFibers(existing._alimentaryFibers),
    _weight(existing._weight)
{
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

void Dish::setName(QString const &name)
{
    if(!name.isEmpty())
    {
        _name = name;
    }
}

bool Dish::operator == (Dish const &existing) const
{
    if(_name == existing._name &&
            qFuzzyCompare(_fats, existing._fats) &&
            qFuzzyCompare(_proteins, existing._proteins) &&
            qFuzzyCompare(_carbohydrates, existing._carbohydrates) &&
            qFuzzyCompare(_organicAcids, existing._organicAcids) &&
            qFuzzyCompare(_alimentaryFibers, existing._alimentaryFibers) &&
            qFuzzyCompare(_weight, existing._weight))
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
    return( !(this->operator==(existing)));
}

float Dish::getEnergyValueOn100() const
{
    return getEnergyValueTotal()*100/_weight;
}

void Dish::write(std::ofstream &file) const
{
    file.write(reinterpret_cast<const char*>(&_fats), sizeof (float));
    file.write(reinterpret_cast<const char*>(&_proteins), sizeof (float));
    file.write(reinterpret_cast<const char*>(&_carbohydrates), sizeof (float));
    file.write(reinterpret_cast<const char*>(&_organicAcids), sizeof (float));
    file.write(reinterpret_cast<const char*>(&_alimentaryFibers), sizeof (float));
    file.write(reinterpret_cast<const char*>(&_weight), sizeof (float));
    int length = static_cast<int>(_name.length()) + 1;
    file.write(reinterpret_cast<char*>(&length), sizeof (int));
    file.write(_name.toStdString().c_str(), length);
}

void Dish::read(std::ifstream &file)
{
    file.read(reinterpret_cast<char*>(&_fats), sizeof (float));
    file.read(reinterpret_cast<char*>(&_proteins), sizeof (float));
    file.read(reinterpret_cast<char*>(&_carbohydrates), sizeof (float));
    file.read(reinterpret_cast<char*>(&_organicAcids), sizeof (float));
    file.read(reinterpret_cast<char*>(&_alimentaryFibers), sizeof (float));
    file.read(reinterpret_cast<char*>(&_weight), sizeof (float));
    int length;
    char *buffer = new char[50];
    file.read(reinterpret_cast<char*>(&length), sizeof (int));
    file.read(reinterpret_cast<char*>(buffer), length);
    _name = buffer;
    delete [] buffer;
}

Dish& Dish::operator = (Dish const &existing)
{
    if(this == &existing)
            return *this;
    _fats = existing._fats;
    _proteins = existing._proteins;
    _carbohydrates = existing._carbohydrates;
    _organicAcids = existing._organicAcids;
    _alimentaryFibers = existing._alimentaryFibers;
    _weight = existing._weight;
    _name = existing._name;
    return *this;

}

float Dish::getEnergyValueTotal() const
{
    return (9.29F*_fats + 4.1F*_proteins + 4.1F*_carbohydrates +
                2.2F*_organicAcids + 1.9F*_alimentaryFibers) * _weight / 100;
}

Base& Dish::operator = (Base const &existing)
{
    *this = *dynamic_cast<const Dish*>(&existing);
    return *this;
}