#include "Fantome.h"

Fantome::Fantome() {
	setType("Sand");
	setSize(100);
	setHealth(80);
	setAttack(100);
	setDefense(20);
	setDescription("Naine de la montagne, Gerare est partie en qu�te d'ennemis puissant et a rencontre ses camarades en chemin.")
}

string Fantome::getType()
{
	return type;
}

void Fantome::setType(string t)
{
	type = t;
}

int Fantome::getSize()
{
	return size;
}

void Fantome::setSize(int s)
{
	size = s;
}

int Fantome::getHealth()
{
	return health;
}

void Fantome::setHealth(int pv)
{
	health = pv;
}

int Fantome::getAttack()
{
	return attack;
}

void Fantome::setAttack(int atk)
{
	attack = atk;
}

int Fantome::getDefense()
{
	return defense;
}

void Fantome::setDefense(int def)
{
	defense = def;
}

string Fantome::getDescription()
{
	return description;
}

void Fantome::setDescription(string d)
{
	description = d;
}