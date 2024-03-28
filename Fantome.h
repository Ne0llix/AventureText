#pragma once
#include <iostream>

using namespace std;


//Nom, role; genre, age, size, description, PV, ATK, DEF

class Fantome
{
private:
	string type;
	int health;
	int attack;
	int defense;
	int size;
	string description;

public:
	Fantome();

	string getType();
	void setType(string t);

	int getSize();
	void setSize(int s);

	int getHealth();
	void setHealth(int pv);

	int getAttack();
	void setAttack(int atk);

	int getDefense();
	void setDefense(int def);

	string getDescription();
	void setDescription(string d);
};