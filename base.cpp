#include "base.h"
#include "iostream"
#include "string.h"
#include "fstream"

Base::Base():
    _kind(BASE),
    _fats(0.0F),
    _proteins(0.0F),
    _carbohydrates(0.0F),
    _organicAcids(0.0F),
    _alimentaryFibers(0.0F),
    _weight(0.0F)
{

}


Base::Base(float const &fats, const float &proteins, const float &carbohydrates,
           const float &organicAcids, const float &alimentaryFibers, const float &weight):
    _kind(BASE),
    _fats(fats > 0 && fats <= 100 ? fats : 0),
    _proteins(proteins > 0 && proteins <= 100 ? proteins : 0),
    _carbohydrates(carbohydrates > 0 && carbohydrates <= 100 ? carbohydrates : 0),
    _organicAcids(organicAcids > 0 && organicAcids <= 100 ? organicAcids : 0),
    _alimentaryFibers(alimentaryFibers > 0 && alimentaryFibers <= 100 ? alimentaryFibers : 0),
    _weight(weight > 0 ? weight : 1)
{
}

Base::Base(Base const &existing):
    _kind(BASE),
    _fats(existing._fats),
    _proteins(existing._proteins),
    _carbohydrates(existing._carbohydrates),
    _organicAcids(existing._organicAcids),
    _alimentaryFibers(existing._alimentaryFibers),
    _weight(existing._weight)
{

}

float Base::getEnergyValueTotal() const
{
    return (9.29F*_fats + 4.1F*_proteins + 4.1F*_carbohydrates +
            2.2F*_organicAcids + 1.9F*_alimentaryFibers) * _weight;
}

Base::~Base()
{

}

bool Base::operator == (Base const & existing) const
{
    return( this->_fats == existing._fats &&
            this->_proteins == existing._proteins &&
            this->_carbohydrates == existing._carbohydrates &&
            this->_organicAcids == existing._organicAcids &&
            this->_alimentaryFibers == existing._alimentaryFibers &&
            this->_weight == existing._weight);
}

bool Base::operator!=( Base const &existing) const
{
    return !(*this == existing);
}

void Base::writeKind(std::ofstream &file)
{
    Kind temp = getKind();
    file.write(reinterpret_cast<char*>(&temp), sizeof (Kind));
}

Kind Base::readKind(std::ifstream &file)
{
    Kind answer;
    file.read(reinterpret_cast<char*>(&answer), sizeof (Kind));
    return answer;
}

void Base::write(std::ofstream &file)
{
    file.write(reinterpret_cast<char*>(&_fats), sizeof (float));
    file.write(reinterpret_cast<char*>(&_proteins), sizeof (float));
    file.write(reinterpret_cast<char*>(&_carbohydrates), sizeof (float));
    file.write(reinterpret_cast<char*>(&_organicAcids), sizeof (float));
    file.write(reinterpret_cast<char*>(&_alimentaryFibers), sizeof (float));
    file.write(reinterpret_cast<char*>(&_weight), sizeof (float));
}

void Base::read(std::ifstream &file)
{
    file.read(reinterpret_cast<char*>(&_fats), sizeof (float));
    file.read(reinterpret_cast<char*>(&_proteins), sizeof (float));
    file.read(reinterpret_cast<char*>(&_carbohydrates), sizeof (float));
    file.read(reinterpret_cast<char*>(&_organicAcids), sizeof (float));
    file.read(reinterpret_cast<char*>(&_alimentaryFibers), sizeof (float));
    file.read(reinterpret_cast<char*>(&_weight), sizeof (float));
}

Base& Base::operator = (Base const &existing)
{
    if(this == &existing)
        return *this;
    _kind = existing._kind;
    _fats = existing._fats;
    _proteins = existing._proteins;
    _carbohydrates = existing._carbohydrates;
    _organicAcids = existing._organicAcids;
    _alimentaryFibers = existing._alimentaryFibers;
    _weight = existing._weight;
    return *this;
}