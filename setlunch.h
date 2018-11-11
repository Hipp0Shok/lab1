#ifndef SETLUNCH_H
#define SETLUNCH_H
#include "dish.h"
enum Days {SUNDAY, MONDAY, THURSDAY, TUESDAY, WEDNESDAY, FRIDAY, SATURDAY};

class SetLunch: public Base
{
public:
    SetLunch();
    ~SetLunch();
    SetLunch(Days &, Dish &, Dish &, Dish&);
    SetLunch(SetLunch &);
    bool operator == (SetLunch const &);
    bool operator != (SetLunch const &);
    float getEnergyValueTotal() const;
    void setSoup(Dish const &);
    void setMainCourse(Dish const &);
    void setDessert(Dish const &);
    void setDay(Days);
    Dish getSoup() const { return _soup;}
    Dish getMainCourse() const {return _mainCourse;}
    Dish getDessert() const { return _dessert;}
    Days getCurrentDay() const { return _currentDay;}
    void write(std::ofstream &);
    void read(std::ifstream &);
    Base& operator = (Base const &);
    SetLunch& operator = (SetLunch const &);
private:
    Dish _soup, _mainCourse, _dessert;
    Days _currentDay;
};

#endif // SETLUNCH_H