#pragma once
#include "Organizm.h"
#include "Zwierze.h"
class Zwierze;
class Swiat;
class Antylopa : public Zwierze
{
public:
	Antylopa();
	Antylopa(int, int, Swiat&);
	void akcja() override;
	void kolizja(int x, int y) override;
	void rysowanie() override;
};

