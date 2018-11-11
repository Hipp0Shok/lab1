#ifndef BASE_H
#define BASE_H
#include "iostream"
#include "string.h"
#include "fstream"
enum Kind {BASE, DISH, SETLUNCH};

class Base
{

public:
    Base();
    Base(float const &, float const &, float const &, float const &, float const &, float const &);
    Base(Base const &);
    virtual ~Base();
    virtual float getEnergyValueTotal() const;
    float getWeight() const { return _weight;}
    float getFats() const { return _fats;}
    float getProteins() const { return _proteins;}
    float getCarbohydrates() const { return _carbohydrates;}
    float getOrganicAcids() const { return _organicAcids;}
    float getAlimentaryFibers() const { return _alimentaryFibers;}
    virtual bool operator == (Base const &);
    virtual bool operator != (Base const &);
    virtual Kind getKind() const {return _kind;}
    virtual void writeKind(std::ofstream &);
    static Kind readKind(std::ifstream &);
    virtual void write(std::ofstream &) = 0;
    virtual void read(std::ifstream &) = 0;
    virtual Base& operator = (Base const &);
protected:
    Kind _kind;
    float _fats, _proteins, _carbohydrates, _organicAcids, _alimentaryFibers, _weight;
};


#endif // BASE_H