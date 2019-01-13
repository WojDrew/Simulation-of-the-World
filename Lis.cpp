#include "Lis.h"
#include <iostream>


Lis::Lis()
{

}
Lis::Lis(int x, int y, Swiat& sw)
	:Zwierze(x, y, sw)
{
	sila = 3;
	inicjatywa = 7;
	no = lis;
}
void Lis::akcja()
{
	int x_t = this->x, y_t = this->y;
	this->losuj(x_t, y_t);
	int k = sw->czy_jest_Org(x_t, y_t);
	if (k != -1)
	{
		while (k == -1 || this->sila >= sw->get_Org(k)->Get_sila())
		{
			this->losuj(x_t, y_t);
			k = sw->czy_jest_Org(x_t, y_t);
		}
		if (k != -1)
			this->kolizja(x_t, y_t);
	}
	this->x = x_t;
	this->y = y_t;
}
void Lis::rysowanie()
{
	std::cout << "L";
}
