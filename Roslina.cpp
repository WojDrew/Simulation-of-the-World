#include "Roslina.h"
#include "Organizm.h"
#include "Trawa.h"
#include "MLecz.h"
#include "Guarana.h"
#include "Wilcze_jagody.h"
#include "Barszcz_sosnowskiego.h"
#include <iostream>
using namespace std;

Roslina::Roslina()
{
}
Roslina::Roslina(int x, int y, Swiat& sw)
	:Organizm(x,y,sw)
{

}

void Roslina::akcja()
{
	wiek++;
	int szansa = rand() % 100;
	int a = 0;

	if (szansa < 10 )
	{
		int x_t = this->x, y_t = this->y;
		if (this->wokol())
		{
			while (a == 0)
			{
				int n = rand() % 4;

				if (n == 0 && x < sw->Get_s_x() && sw->czy_jest_Org(x + 1, y) == -1)
				{
					x_t++;
					a++;
				}
				else if (n == 1 && x > 1 && sw->czy_jest_Org(x - 1, y) == -1)
				{
					x_t--;
					a++;
				}
				else if (n == 2 && y < sw->Get_s_y() && sw->czy_jest_Org(x, y + 1) == -1)
				{
					y_t++;
					a++;
				}
				else if (n == 3 && y > 1 && sw->czy_jest_Org(x, y - 1) == -1)
				{
					y_t--;
					a++;
				}
			}
			switch (this->no)
			{
			case trawa:
			{
				Trawa * tr = new Trawa(x_t, y_t, *sw);
				this->sw->dodaj_organizm(tr);
				break;
			}
			case mlecz:
			{
				Mlecz * ml = new Mlecz(x_t, y_t, *sw);
				this->sw->dodaj_organizm(ml);
				break;
			}
			case guarana:
			{
				Guarana * gu = new Guarana(x_t, y_t, *sw);
				this->sw->dodaj_organizm(gu);
				break;
			}
			case wilcze_jagody:
			{
				Wilcze_jagody * wj = new Wilcze_jagody(x_t, y_t, *sw);
				this->sw->dodaj_organizm(wj);
				break;
			}
			case barszcz_sosnowskiego:
			{
				Barszcz_sosnowskiego * bs = new Barszcz_sosnowskiego(x_t, y_t, *sw);
				this->sw->dodaj_organizm(bs);
				break;
			}
			default:
				break;
			}
		}
	}
}
void Roslina::kolizja(int x, int y)
{

}

Roslina::~Roslina()
{
}
