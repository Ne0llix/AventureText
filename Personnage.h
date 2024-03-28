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
	int attack;
	int defense;
	int age;
	int size;
	string description;

public:
	Personnage();

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

	int getAttack();
	void setAttack(int atk);

	int getDefense();
	void setDefense(int def);

	string getDescription();
	void setDescription(string d);
};

