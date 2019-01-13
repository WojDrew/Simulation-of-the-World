#include "Czlowiek.h"
#include <conio.h>
#include <iostream>


Czlowiek::Czlowiek()
{

}
Czlowiek::Czlowiek(int x, int y, Swiat& sw)
	:Zwierze(x, y, sw)
{
	sila = 5;
	inicjatywa = 4;
	no = czlowiek;
	dni = 0;
	czy_moza_ability = true;
	specjaAbility = false;
}
void Czlowiek::akcja()
{
	if (dni == 5)
		specjaAbility = false;
	else if (dni == 10)
	{
		czy_moza_ability = true;
		dni = 0;
	}
	else if (czy_moza_ability == false)
		dni++;
	int x_t = this->x, y_t = this->y;
	bool flaga = true;
	while (flaga)
	{
		unsigned char znak = _getch();
		switch (znak)
		{
		case 0:
		case 224:
			znak = _getch();
			flaga = false;
			switch (znak)
			{
			case 72://gora
				y_t--;
				break;
			case 80://dol
				y_t++;
				break;
			case 75://lewo
				x_t--;
				break;
			case 77://prawo
				x_t++;
				break;
			default:
				break;
			}
			break;
		case 'a':
			if (czy_moza_ability)
			{
				specjaAbility = true;
				czy_moza_ability = false;
			}
		default:
			flaga = true;

		}
	}
	if (specjaAbility)
	{
		string info = "tarcza Alzura dziala";
		sw->dodaj_info(info);
	}
	else
	{
		string info = "tarcza Alzura nie dziala";
		sw->dodaj_info(info);
	}
	int k = sw->czy_jest_Org(x_t, y_t);
	if (k != -1)
		this->kolizja(x_t, y_t);
	else
	{
		this->x = x_t;
		this->y = y_t;
	}

}
bool Czlowiek::kolizja_obronna(Organizm* o)
{
	if (specjaAbility && this->wokol())
	{
		int x_t = o->Get_x(), y_t = o->Get_y();
		int k = sw->czy_jest_Org(x_t, y_t);
		while (k != -1)
		{
			this->losuj(x_t, y_t);
			k = sw->czy_jest_Org(x_t, y_t);
		}
		string info = "Tarcza Alzura zostala uzyta";
		sw->dodaj_info(info);
		return true;
	}
	else
		return false;

}
bool Czlowiek::get_specjal_Ability()
{
	return specjaAbility;
}
int Czlowiek::get_dni()
{
	return dni;
}
void Czlowiek::rysowanie()
{
	std::cout << "C";
}
