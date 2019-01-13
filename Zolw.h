#pragma once
#include "Organizm.h"
#include "Zwierze.h"
class Zwierze;
class Swiat;
class Zolw : public Zwierze
{
public:
	Zolw();
	Zolw(int, int, Swiat&);
	void akcja() override;
	bool czyOdbilAtak(Organizm* o) override;
	void rysowanie() override;
};

