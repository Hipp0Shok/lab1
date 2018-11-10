#ifndef SETLUNCH_H
#define SETLUNCH_H
#include "list.h"
#include "base.h"


class SetLunch : public Base
{
public:
    virtual float getEnergyValue() const;
    void addNode(Dish const &);
    void deleteNode(List::Iterator const &);
private:
    List dishSet;
};

#endif // SETLUNCH_H