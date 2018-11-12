#include "setlunch.h"

SetLunch::SetLunch():
    Base(),
    _currentDay(SUNDAY)
{
    _kind = SETLUNCH;
}
SetLunch::SetLunch(Days &day, Dish &soup, Dish &mainCourse, Dish&dessert):
    _soup(soup),
    _mainCourse(mainCourse),
    _dessert(dessert),
    _currentDay(day >= SUNDAY && day <= SATURDAY ? day : SUNDAY)
{
    _kind = SETLUNCH;
    _proteins = _soup.getProteins() + _mainCourse.getProteins() + _dessert.getProteins();
    _fats = _soup.getFats() + _mainCourse.getFats() + _dessert.getFats();
    _carbohydrates = _soup.getCarbohydrates() + _mainCourse.getCarbohydrates()
            + _dessert.getCarbohydrates();
    _organicAcids = _soup.getOrganicAcids() + _mainCourse.getOrganicAcids()
            + _dessert.getOrganicAcids();
    _alimentaryFibers = _soup.getAlimentaryFibers() + _mainCourse.getAlimentaryFibers()
            + _dessert.getAlimentaryFibers();
    _weight = _soup.getWeight() + _mainCourse.getWeight() + _dessert.getWeight();
}
SetLunch::SetLunch(SetLunch &existing):
    Base(existing),
    _soup(existing._soup),
    _mainCourse(existing._mainCourse),
    _dessert(existing._dessert),
    _currentDay(existing._currentDay)
{
    _kind = SETLUNCH;
}

SetLunch::~SetLunch()
{}

float SetLunch::getEnergyValueTotal() const
{
    return _soup.getEnergyValueTotal() + _mainCourse.getEnergyValueTotal() + _dessert.getEnergyValueTotal();
}

void SetLunch::setSoup(Dish const &soup)
{
    _fats -= _soup.getFats();
    _proteins -= _soup.getProteins();
    _carbohydrates -= _soup.getCarbohydrates();
    _organicAcids -= _soup.getOrganicAcids();
    _alimentaryFibers -= _soup.getAlimentaryFibers();
    _weight -= _soup.getWeight();
    _soup = soup;
    _fats += _soup.getFats();
    _proteins += _soup.getProteins();
    _carbohydrates += _soup.getCarbohydrates();
    _organicAcids += _soup.getOrganicAcids();
    _alimentaryFibers += _soup.getAlimentaryFibers();
    _weight += _soup.getWeight();
}

void SetLunch::setMainCourse(Dish const &mainCourse)
{
    _fats -= _mainCourse.getFats();
    _proteins -= _mainCourse.getProteins();
    _carbohydrates -= _mainCourse.getCarbohydrates();
    _organicAcids -= _mainCourse.getOrganicAcids();
    _alimentaryFibers -= _mainCourse.getAlimentaryFibers();
    _weight -= _mainCourse.getWeight();
    _mainCourse = mainCourse;
    _fats += _mainCourse.getFats();
    _proteins += _mainCourse.getProteins();
    _carbohydrates += _mainCourse.getCarbohydrates();
    _organicAcids += _mainCourse.getOrganicAcids();
    _alimentaryFibers += _mainCourse.getAlimentaryFibers();
    _weight += _mainCourse.getWeight();
}

void SetLunch::setDessert(Dish const &dessert)
{
    _fats -= _dessert.getFats();
    _proteins -= _dessert.getProteins();
    _carbohydrates -= _dessert.getCarbohydrates();
    _organicAcids -= _dessert.getOrganicAcids();
    _alimentaryFibers -= _dessert.getAlimentaryFibers();
    _weight -= _dessert.getWeight();
    _dessert = dessert;
    _fats += _dessert.getFats();
    _proteins += _dessert.getProteins();
    _carbohydrates += _dessert.getCarbohydrates();
    _organicAcids += _dessert.getOrganicAcids();
    _alimentaryFibers += _dessert.getAlimentaryFibers();
    _weight += _dessert.getWeight();
}

void SetLunch::setDay(Days existing)
{
    if(existing >= SUNDAY && existing <= SATURDAY)
    {
        _currentDay = existing;
    }
}

void SetLunch::write(std::ofstream &file)
{
    Base::write(file);
    _soup.write(file);
    _mainCourse.write(file);
    _dessert.write(file);
    file.write(reinterpret_cast<char*>(&_currentDay), sizeof (Days));
}

void SetLunch::read(std::ifstream &file)
{
    Base::read(file);
    _soup.read(file);
    _mainCourse.read(file);
    _dessert.read(file);
    file.read(reinterpret_cast<char*>(&_currentDay), sizeof (Days));
}

bool SetLunch::operator==(SetLunch const &existing) const
{
    if(Base::operator==(existing) && _soup == existing._soup &&
            _mainCourse == existing._mainCourse && _dessert == existing._dessert)
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
    if(!(operator==(existing)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

Base& SetLunch::operator = (Base const &existing)
{
    *this = operator=(*dynamic_cast< const SetLunch* >(&existing));
    return *this;
}

SetLunch& SetLunch::operator = (SetLunch const &existing)
{
    if(this == &existing)
    {
        return *this;
    }
    else
    {
    Base::operator=(existing);
    _soup = existing._soup;
    _mainCourse = existing._mainCourse;
    _dessert = existing._dessert;
    _currentDay = existing._currentDay;
    return *this;
    }
}
