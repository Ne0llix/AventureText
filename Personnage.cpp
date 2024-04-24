#include "Personnage.h"

Personnage::Personnage(string n, string r, string g, int a, int s, int pv,int MaxPv, int atk, int atkspe, string atkspen, int def, string d, bool ID) {
	setName(n); 
	setRole(r);
	setGender(g);
	setAge(a);
	setSize(s);
	setHealth(pv);
	setMaxHealth(MaxPv);
	setAttack(atk);
	setAttackSpecial(atkspe);
	setAttackSpecialName(atkspen);
	setDefense(def);
	setDescription(d);
	setIsDead(ID);
}
Personnage::Personnage() {
	setName("Jean");
	setRole("Tank");
	setGender("Homme");
	setAge(28);
	setSize(185);
	setHealth(110);
	setMaxHealth(110);
	setAttack(60);
	setAttackSpecial(105);
	setAttackSpecialName("Paquet d'unite");
	setDefense(35);
	setDescription("Grand et musculeux, Jean est naturellement devenu le Tank du groupe.En quête d'ennemis puissants il est pret a se battre contre n'importe qui pour l'Unite.");
	setIsDead(false);
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

int Personnage::getMaxHealth()
{
	return MaxHealth;
}

void Personnage::setMaxHealth(int MaxPv)
{
	MaxHealth = MaxPv;
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

bool Personnage::getIsDead()
{
	return IsDead;
}

void Personnage::setIsDead(bool ID)
{
	IsDead = ID;
}

void Personnage::ReceiveHeal(int HealValue)
{
	setHealth(getHealth() + HealValue);
	if (getHealth() > getMaxHealth()) {
		setHealth(getMaxHealth());
	}
}

 void Personnage::ReceiveAttack(int AttackValue)
{
	 if ((AttackValue - getDefense()) > 0) {
		 setHealth(getHealth() - (AttackValue - getDefense()));
	 }
	 else {
		 setHealth(getHealth());
	 }
	
}
