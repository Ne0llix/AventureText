#pragma once
#include <iostream>

using namespace std;
class Inventaire
{
private:
	string name;
	int nombre;
	int soin;

public:
	Inventaire(string n, int nb, int s);

	string GetName();
	void setName(string n);

	int GetNombre();
	void setNombre(int nb);

	int GetSoin();
	void setSoin(int s);

	virtual void UseObject();
};

