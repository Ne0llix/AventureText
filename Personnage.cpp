#include "Personnage.h"

Personnage::Personnage(string n, string r, string g, int a, int s, int pv, int atk, int atkspe, string atkspen, int def, string d) {
	setName(n); 
	setRole(r);
	setGender(g);
	setAge(a);
	setSize(s);
	setHealth(pv);
	setAttack(atk);
	setAttackSpecial(atkspe);
	setAttackSpecialName(atkspen);
	setDefense(def);
	setDescription(d);
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

int Personnage::getAttackSpecial()
{
	return attackSpecial;
}

void Personnage::setAttackSpecial(int atkspe)
{
	attackSpecial = atkspe;
}

string Personnage::getAttackSpecialName()
{
	return attackSpecialName;
}

void Personnage::setAttackSpecialName(string atkspen)
{
	attackSpecialName = atkspen;
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
