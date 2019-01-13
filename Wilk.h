#pragma once
#include "Organizm.h"
#include "Zwierze.h"
class Zwierze;
class Swiat;
class Wilk : public Zwierze
{
public:
	Wilk();
	Wilk(int, int, Swiat&);
	void rysowanie() override;
};
