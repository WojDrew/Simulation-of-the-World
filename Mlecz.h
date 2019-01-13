#pragma once
#include "Organizm.h"
#include "Roslina.h"
class Organizm;
class Mlecz : public Roslina
{
public:
	Mlecz();
	Mlecz(int, int, Swiat&);
	void akcja() override;
	void rysowanie() override;
};

