#ifndef SETLUNCH_H
#define SETLUNCH_H
#include "list.h"
#include "base.h"


class SetLunch : public Base
{
public:
    virtual float getEnergyValue() const;
private:
    List dishSet;
};

#endif // SETLUNCH_H