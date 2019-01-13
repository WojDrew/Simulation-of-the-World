#pragma once
#include "Organizm.h"
#include "Roslina.h"
class Organizm;
class Guarana : public Roslina
{
public:
	Guarana();
	Guarana(int, int, Swiat&);
	int boostStr() override;
	void rysowanie() override;
};

