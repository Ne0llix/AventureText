#pragma once
#include <iostream>

using namespace std;


//Nom, role; genre, age, size, description, PV, ATK, DEF

class Personnage
{
private:
	string name;
	string role;
	string gender;
	int health;
	int MaxHealth;
	int attack;
	int attackSpecial;
	string attackSpecialName;
	int defense;
	int age;
	int size;
	string description;

public:
	Personnage(string n, string r, string g, int a, int s, int pv,int MaxPv, int atk, int atkspe, string atkspen, int def, string d);

	string getName();
	void setName(string n);

	string getRole();
	void setRole(string r);

	string getGender();
	void setGender(string g);

	int getAge();
	void setAge(int a);

	int getSize();
	void setSize(int s);

	int getHealth();
	void setHealth(int pv);

	int getMaxHealth();
	void setMaxHealth(int MaxPv);

	int getAttack();
	void setAttack(int atk);

	int getAttackSpecial();
	void setAttackSpecial(int atkspe);

	string getAttackSpecialName();
	void setAttackSpecialName(string atkspen);
	 
	int getDefense();
	void setDefense(int def);

	string getDescription();
	void setDescription(string d);

	void ReceiveHeal(int HealValue);

	void ReceiveAttack(int AttackValue);
};

