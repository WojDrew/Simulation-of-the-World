#pragma once
#include "Organizm.h"
#include "Roslina.h"
class Organizm;
class Trawa : public Roslina
{
public:
	Trawa();
	Trawa(int, int, Swiat&);
	void rysowanie() override;
};

