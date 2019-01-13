#pragma once
#include "Organizm.h"
#include "Zwierze.h"
class Zwierze;
class Swiat;
class Czlowiek : public Zwierze
{
	bool specjaAbility;
	int dni;
	bool czy_moza_ability;
public:
	Czlowiek();
	Czlowiek(int, int, Swiat&);
	void akcja() override;
	bool kolizja_obronna(Organizm* o) override;
	bool get_specjal_Ability();
	int get_dni();
	void rysowanie() override;
};

