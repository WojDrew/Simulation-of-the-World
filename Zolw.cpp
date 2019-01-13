#include "Zolw.h"
#include <iostream>


Zolw::Zolw()
{

}
Zolw::Zolw(int x, int y, Swiat& sw)
	:Zwierze(x, y, sw)
{
	sila = 2;
	inicjatywa = 1;
	no = zolw;
}
void Zolw::akcja()
{
	int a = rand() % 100;
	if (a < 25)
	{
		int x_t = this->x, y_t = this->y;
		this->losuj(x_t, y_t);
		int k = sw->czy_jest_Org(x_t, y_t);
		if (k != -1)
			this->kolizja(x_t, y_t);
		else
		{
			this->x = x_t;
			this->y = y_t;
		}
	}
}
bool Zolw::czyOdbilAtak(Organizm* o)
{
	if (o->Get_sila() < 5)
		return true;
	else
		return false;
}
void Zolw::rysowanie()
{
	std::cout << "Z";
}
