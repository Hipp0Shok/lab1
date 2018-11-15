#ifndef DISH_H
#define DISH_H
#include "base.h"

class Dish: public Base
{
public:
    Dish();
    Dish(std::string const &, float const &, float const &, float const &, float const &, float const &, float const &);
    Dish(Dish const &);
    ~Dish();
    float getEnergyValueOn100() const;
    float getEnergyValueTotal() const;
    void setFats(float const &);
    void setProteins(float const &);
    void setCarbohydrates(float const &);
    void setOrganicAcids(float const &);
    void setAlimentaryFibers(float const &);
    void setWeight(float const &);
    float getWeight() const { return _weight;}
    float getFats() const { return _fats;}
    float getProteins() const { return _proteins;}
    float getCarbohydrates() const { return _carbohydrates;}
    float getOrganicAcids() const { return _organicAcids;}
    float getAlimentaryFibers() const { return _alimentaryFibers;}
    std::string getName() const { return _name;}
    void setName(std::string const &);
    bool operator == (Dish const &) const;
    bool operator != (Dish const &) const ;
    Dish& operator = (Dish const &);
    void write(std::ofstream &) const;
    void read(std::ifstream &);
    Kind getKind() const {return DISH;}
    Base& operator = (Base const &);
private:
    std::string _name;
    float _fats, _proteins, _carbohydrates, _organicAcids, _alimentaryFibers, _weight;
};

#endif // DISH_H