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
    void setFats(float const &);
    void setProteins(float const &);
    void setCarbohydrates(float const &);
    void setOrganicAcids(float const &);
    void setAlimentaryFibers(float const &);
    void setWeight(float const &);
    std::string getName() const { return _name;}
    void setName(std::string const &);
    bool operator == (Dish const &) const;
    bool operator != (Dish const &) const ;
    Base& operator = (Base const &);
    Dish& operator = (Dish const &);
    void write(std::ofstream &);
    void read(std::ifstream &);
private:
    std::string _name;
};

#endif // DISH_H