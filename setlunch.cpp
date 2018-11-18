#include "setlunch.h"


SetLunch::SetLunch()
{
}
SetLunch::SetLunch(const Dish &soup, const Dish &mainCourse, const Dish&dessert):
    _soup(soup),
    _mainCourse(mainCourse),
    _dessert(dessert)
{
}
SetLunch::SetLunch(const SetLunch &existing):
    Base(existing),
    _soup(existing._soup),
    _mainCourse(existing._mainCourse),
    _dessert(existing._dessert)
{
}

SetLunch::~SetLunch()
{}

float SetLunch::getEnergyValueTotal() const
{
    return _soup.getEnergyValueTotal() + _mainCourse.getEnergyValueTotal() + _dessert.getEnergyValueTotal();
}

void SetLunch::setSoup(Dish const &soup)
{
    _soup = soup;
}

void SetLunch::setMainCourse(Dish const &mainCourse)
{
    _mainCourse = mainCourse;
}

void SetLunch::setDessert(Dish const &dessert)
{
    _dessert = dessert;
}

void SetLunch::write(std::ofstream &file) const
{
    _soup.write(file);
    _mainCourse.write(file);
    _dessert.write(file);
}

void SetLunch::read(std::ifstream &file)
{
    _soup.read(file);
    _mainCourse.read(file);
    _dessert.read(file);
}

bool SetLunch::operator==(SetLunch const &existing) const
{
    if( _soup == existing._soup &&
            _mainCourse == existing._mainCourse &&
            _dessert == existing._dessert)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool SetLunch::operator!=(SetLunch const &existing) const
{
    return(!this->operator==(existing));
}

SetLunch& SetLunch::operator = (SetLunch const &existing)
{
    if(this == &existing)
    {
        return *this;
    }
    else
    {
    _soup = existing._soup;
    _mainCourse = existing._mainCourse;
    _dessert = existing._dessert;
    return *this;
    }
}

Base& SetLunch::operator = (Base const &existing)
{
    *this = *dynamic_cast<const SetLunch*>(&existing);
    return *this;
}

QString SetLunch::getWeightTotal() const
{
    return(QString::number(_soup.getWeight()) + '/' +
           QString::number(_mainCourse.getWeight()) + '/' +
           QString::number(_dessert.getWeight()));
}
QString SetLunch::getNameTotal() const
{
    return(_soup.getName() + '/' +
           _mainCourse.getName() + '/' +
           _dessert.getName());
}