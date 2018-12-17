#ifndef SETLUNCH_H
#define SETLUNCH_H
#include "dish.h"

class SetLunch: public Base
{
public:
    SetLunch();
    ~SetLunch();
    SetLunch(const Dish &, const Dish &, const Dish&);
    SetLunch(const SetLunch &);
    bool operator == (SetLunch const &) const;
    bool operator != (SetLunch const &) const;
    float getEnergyValueTotal() const;
    void setSoup(Dish const &);
    void setMainCourse(Dish const &);
    void setDessert(Dish const &);
    Dish getSoup() const { return _soup;}
    Dish getMainCourse() const {return _mainCourse;}
    Dish getDessert() const { return _dessert;}
    void write(std::ofstream &) const;
    void read(std::ifstream &);
    Kind getKind() const {return SETLUNCH;}
    SetLunch& operator = (SetLunch const &);
    Base& operator = (Base const &);
    QString getWeightTotal() const;
    QString getNameTotal() const;
private:
    Dish _soup, _mainCourse, _dessert;
};

#endif // SETLUNCH_H