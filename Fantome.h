#pragma once
#include <iostream>

using namespace std;


//Nom, role; genre, age, size, description, PV, ATK, DEF
enum class Element {
	normal,
	water,
	fire,
	sand,
	boss
};

class Fantome
{
private:
	Element elementType;
	int health;
	int attack;
	int defense;
	int size;
	string description;

public:
	Fantome();

	Element getElementType();
	std::string getElementType_ToString();
	void setElementType(Element e);
	void setElementType(std::string userElement);

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