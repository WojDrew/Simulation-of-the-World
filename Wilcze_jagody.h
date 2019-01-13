#pragma once
#include "Organizm.h"
#include "Roslina.h"
class Organizm;
class Wilcze_jagody : public Roslina
{
public:
	Wilcze_jagody();
	Wilcze_jagody(int, int, Swiat&);
	bool smierc() override;
	void rysowanie() override;
};

