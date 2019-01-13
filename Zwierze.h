#pragma once
#include <cstdlib>
#include <ctime>
#include "Organizm.h"
class Swiat;
class Organizm;




class Zwierze: public Organizm
{
public:
	Zwierze();
	Zwierze(int x, int y, Swiat& sw);
	virtual void akcja() override;
	virtual void kolizja(int x, int y) override;
	virtual ~Zwierze();
};


