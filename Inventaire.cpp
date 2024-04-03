#include "Inventaire.h"

Inventaire::Inventaire(string n, int nb, int s) {
	setName(n);
	setNombre(nb);
	setSoin(s);
}
string Inventaire::GetName()
{
	return name;
}

void Inventaire::setName(string n)
{
	name = n;
}

int Inventaire::GetNombre()
{
	return nombre;
}

void Inventaire::setNombre(int nb)
{
	nombre = nb;
}

int Inventaire::GetSoin()
{
	return soin;
}

void Inventaire::setSoin(int s)
{
	soin = s;
}

void Inventaire::UseObject() {
	setNombre(GetNombre() - 1);
}
#include "Inventaire.h"
