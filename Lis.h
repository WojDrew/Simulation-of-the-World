#pragma once
#include "Organizm.h"
#include "Zwierze.h"
class Zwierze;
class Swiat;
class Lis : public Zwierze
{
public:
	Lis();
	Lis(int, int, Swiat&);
	void akcja() override;
	void rysowanie() override;
};
