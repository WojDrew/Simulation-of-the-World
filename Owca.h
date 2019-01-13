#pragma once
#include "Organizm.h"
#include "Zwierze.h"
class Zwierze;
class Swiat;
class Owca : public Zwierze
{
public:
	Owca();
	Owca(int, int, Swiat&);
	void rysowanie() override;
};
