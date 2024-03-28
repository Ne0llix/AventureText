#include "Fantome.h"

Fantome::Fantome() {
	setElementType("Sand");
	setSize(100);
	setHealth(80);
	setAttack(100);
	setDefense(20);
	setDescription("Naine de la montagne, Gerare est partie en quête d'ennemis puissant et a rencontre ses camarades en chemin.");
}

Element Fantome::getElementType()
{
	return elementType;
}

std::string Fantome::getElementType_ToString()
{
	switch (elementType) {
	case Element::normal:
		return "normal";
	case Element::water:
		return "water";
	case Element::ice:
		return "ice";
	case Element::fire:
		return "fire";
	case Element::sand:
		return "sand";
	case Element::boss:
		return "boss";
	default:
		return "normal";
	}
}

void Fantome::setElementType(Element e)
{
	elementType = e;
}

void Fantome::setElementType(std::string userElement)
{
	if (userElement == "normal") {
		elementType = Element::normal;
	}
	else if (userElement == "water") {
		elementType = Element::water;

	}
	else if (userElement == "ice") {
		elementType = Element::ice;

	}
	else if (userElement == "fire") {
		elementType = Element::fire;

	}
	else if (userElement == "sand") {
		elementType = Element::sand;

	}
	else if (userElement == "boss") {
		elementType = Element::boss;

	}
	else {
		elementType = Element::normal;
	}
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