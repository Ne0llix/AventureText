#pragma once
#include <iostream>

using namespace std;


//Nom, role; genre, age, size, description, PV, ATK, DEF
enum class Element {
	normal,
	water,
	ice,
	fire,
	sand,
	boss
};

class Fantome
{
private:
	Element elementType;
	int health;
	int MaxHealth;
	int attack;
	int defense;
	int size;
	string description;

public:
	Fantome(string e, int s, int pv, int Maxpv, int atk, int def, string d);

	Element getElementType();
	std::string getElementType_ToString();
	void setElementType(Element e);
	void setElementType(std::string userElement);

	int getSize();
	void setSize(int s);

	int getHealth();
	void setHealth(int pv);

	int getMaxHealth();
	void setMaxHealth(int Maxpv);


	int getAttack();
	void setAttack(int atk);

	int getDefense();
	void setDefense(int def);

	string getDescription();
	void setDescription(string d);

	void ReceiveAttack(int AttackValue);
};