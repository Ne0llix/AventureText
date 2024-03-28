#include "Personnage.h"

Personnage::Personnage() {
	setName("Gerare");
	setRole("Guerriere");
	setGender("Femme");
	setAge(118);
	setSize(100);
	setHealth(80);
	setAttack(100);
	setDefense(20);
	setDescription("Naine de la montagne, Gerare est partie en quête d'ennemis puissant et a rencontre ses camarades en chemin.")
}

string Personnage::getName()
{
	return name;
}

void Personnage::setName(string n)
{
	name = n;
}

string Personnage::getRole()
{
	return role;
}

void Personnage::setRole(string r)
{
	role = r;
}

string Personnage::getGender()
{
	return gender;
}

void Personnage::setGender(string g)
{
	gender = g;
}

int Personnage::getAge()
{
	return age;
}

void Personnage::setAge(int a)
{
	age = a;
}

int Personnage::getSize()
{
	return size;
}

void Personnage::setSize(int s)
{
	size = s;
}

int Personnage::getHealth()
{
	return health;
}

void Personnage::setHealth(int pv)
{
	health = pv;
}

int Personnage::getAttack()
{
	return attack;
}

void Personnage::setAttack(int atk)
{
	attack = atk;
}

int Personnage::getDefense()
{
	return defense;
}

void Personnage::setDefense(int def)
{
	defense = def;
}

string Personnage::getDescription()
{
	return description;
}

void Personnage::setDescription(string d)
{
	description = d;
}
