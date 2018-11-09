#include "setlunch.h"

float SetLunch::getEnergyValue()
{
    SetLunch::Iterator iter;
    float energyValue = 0.0F;
    for(iter = begin(); iter != nullptr; iter++)
    {
        energyValue += (*iter).getEnergyValueTotal();
    }
    return energyValue;
}
