#ifndef BASE_H
#define BASE_H
#include "iostream"
#include "string.h"


class Base
{

public:
    Base();
    Base(std::string const &, float const &, float const &, float const &, float const &, float const &, float const &);
    Base(Base const &);
    virtual ~Base();
    virtual float getEnergyValueTotal() const;
    float getEnergyValueOn100() const;
    virtual std::string getName() const { return _name;}
    virtual void setName(std::string const &);
    virtual float getWeight() const { return _weight;}
    virtual void setWeight(float const &);
    virtual float getFats() const { return _fats;}
    virtual float getProteins() const { return _proteins;}
    virtual float getCarbohydrates() const { return _carbohydrates;}
    virtual float getOrganicAcids() const { return _organicAcids;}
    virtual float getAlimentaryFibers() const { return _alimentaryFibers;}
    bool operator == (Base const &);
    bool operator != (Base const &);
protected:
    std::string _name;
    float _fats, _proteins, _carbohydrates, _organicAcids, _alimentaryFibers, _weight;
};

#endif // BASE_H