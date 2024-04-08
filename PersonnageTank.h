#pragma once
#include "Personnage.h"

class PersonnageTank : public Personnage
{
private : 
	bool IsTankTrue;

public :
	PersonnageTank();

	bool getIsTankTrue();
	void setIsTankTrue(bool t);

};

