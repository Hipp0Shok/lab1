#include "base.h"
#include "iostream"
#include "string.h"

Base::Base():
    _name("Water"),
    _fats(0.0F),
    _proteins(0.0F),
    _carbohydrates(0.0F),
    _organicAcids(0.0F),
        _alimentaryFibers(0.0F),
    _weight(0.0F)
{

}


Base::Base(std::string const &name, float const &fats, const float &proteins, const float &carbohydrates,
           const float &organicAcids, const float &alimentaryFibers, const float &weight):
    _name(!name.empty() ? name : "Water"),
    _fats(fats > 0 && fats <= 100 ? fats : 0),
    _proteins(proteins > 0 && proteins <= 100 ? proteins : 0),
    _carbohydrates(carbohydrates > 0 && carbohydrates <= 100 ? carbohydrates : 0),
    _organicAcids(organicAcids > 0 && organicAcids <= 100 ? organicAcids : 0),
    _alimentaryFibers(alimentaryFibers > 0 && alimentaryFibers <= 100 ? alimentaryFibers : 0),
    _weight(weight > 0 ? weight : 1)
{
}

Base::Base(Base const &existing):
    _name(existing._name),
    _fats(existing._fats),
    _proteins(existing._proteins),
    _carbohydrates(existing._carbohydrates),
    _organicAcids(existing._organicAcids),
    _alimentaryFibers(existing._alimentaryFibers),
    _weight(existing._weight)
{

}

float Base::getEnergyValueOn100() const
{
    return 9.29F*_fats + 4.1F*_proteins + 4.1F*_carbohydrates +
                2.2F*_organicAcids + 1.9F*_alimentaryFibers;
}

float Base::getEnergyValueTotal() const
{
    return getEnergyValueOn100()*_weight/100;
}

void Base::setName(std::string const &name)
{
    if(!name.empty())
    {
        _name = name;
    }
}

void Base::setWeight(float const &weight)
{
    if(weight >= 0)
    {
        _weight = weight;
    }
}

Base::~Base()
{

}

bool Base::operator == (Base const & existing)
{
    return( this->_name == existing._name &&
            this->_fats == existing._fats &&
            this->_proteins == existing._proteins &&
            this->_carbohydrates == existing._carbohydrates &&
            this->_organicAcids == existing._organicAcids &&
            this->_alimentaryFibers == existing._alimentaryFibers &&
            this->_weight == existing._weight);
}

bool Base::operator!=( Base const &existing)
{
    return !(*this == existing);
}