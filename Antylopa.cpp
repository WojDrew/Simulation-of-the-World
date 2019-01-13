#include "Antylopa.h"
#include <iostream>
Antylopa::Antylopa()
{

}
Antylopa::Antylopa(int x, int y, Swiat& sw)
	:Zwierze(x, y, sw)
{
	sila = 4;
	inicjatywa = 4;
	no = antylopa;
}
void Antylopa::akcja()
{

	int x_t = this->x, y_t = this->y;
	this->losuj(x_t, y_t);
	if (x_t > this->x)
		x_t++;
	else if (x_t < this->x)
		x_t--;
	else if (y_t > this->y)
		y_t++;
	else if (y_t < this->y)
		y_t--;
	int k = sw->czy_jest_Org(x_t, y_t);
	if (k != -1)
		this->kolizja(x_t, y_t);
	else
	{
		this->x = x_t;
		this->y = y_t;
	}
}
void Antylopa::kolizja(int x, int y)
{
	int k = sw->czy_jest_Org(x, y);
	int n = rand() % 100;
	if (n < 50)
		this->Zwierze::kolizja(x, y);
	else if (sw->get_Org(k)->wokol())
	{
		while (sw->czy_jest_Org(x, y) != -1)
		{
			this->losuj(x, y);
		}
		this->x = x;
		this->y = y;
	}
	else
		this->Zwierze::kolizja(x, y);
}
void Antylopa::rysowanie()
{
	std::cout << "A";
}
