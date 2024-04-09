#include "PersonnageTank.h"

PersonnageTank::PersonnageTank()
{
    setIsTankTrue(true);
}
bool PersonnageTank::getIsTankTrue()
{
    return IsTankTrue;
}

void PersonnageTank::setIsTankTrue(bool t)
{
    IsTankTrue = t;
}

void PersonnageTank::PaquetUnite(bool TankTrue)
{
    if (TankTrue) {

    }
    setIsTankTrue(false);
}
