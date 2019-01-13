#pragma once
#include "Organizm.h"
class Organizm;


class Roslina : public Organizm
{
public:
	Roslina();
	Roslina(int, int, Swiat&);
	virtual void akcja() override;
	virtual void kolizja(int x, int y) override;
	virtual ~Roslina();
};
