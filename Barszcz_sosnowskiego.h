#pragma once
#include "Organizm.h"
#include "Roslina.h"
class Organizm;
class Barszcz_sosnowskiego : public Roslina
{
public:
	Barszcz_sosnowskiego();
	Barszcz_sosnowskiego(int, int, Swiat&);
	void akcja() override;
	bool smierc() override;
	void rysowanie() override;
};
