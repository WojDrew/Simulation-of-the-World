#include "Zwierze.h"
#include "Swiat.h"
#include "Organizm.h"
#include "Wilk.h"
#include "Owca.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Czlowiek.h"
#include <conio.h>
#include <iostream>
#include <string>
using namespace std;

Zwierze::Zwierze()
{

}
Zwierze::Zwierze(int x, int y, Swiat& sw)
	:Organizm(x,y,sw)
{

}
void Zwierze::akcja()
{
	wiek++;
	//int a = 0;
	int x_t = this->x, y_t = this->y;
	this->losuj(x_t,y_t);
	/*while (a == 0)
	{
		int n = rand() % 4;
		if (n == 0 && this->x < sw->Get_s_x())
		{
			x_t++;
			a++;
		}
		else if (n == 1 && this->x > 1)
		{
			x_t--;
			a++;
		}
		else if (n == 2 && this->y < sw->Get_s_y())
		{
			y_t++;
			a++;
		}
		else if (n == 3 && this->y > 1)
		{
			y_t--;
			a++;
		}
	}*/
	int k = sw->czy_jest_Org(x_t, y_t);
	if (sw->czy_jest_Org(x_t, y_t) != -1)
	{
		if(sw->get_Org(k)->kolizja_obronna(this) == false)
			this->kolizja(x_t, y_t);
	}
	else
	{
		this->x = x_t;
		this->y = y_t;
	}
}
void Zwierze::kolizja(int x, int y)
{
	int k = sw->czy_jest_Org(x,y); 
	if (this->no == sw->get_Org(k)->nazwa())
	{
		int a = 0;
		int x_t = this->x, y_t = this->y;
		if (this->wokol())
		{
			while (a == 0)
			{
				int n = rand() % 4;
				if (n == 0  && sw->czy_jest_Org(this->x + 1, this->y) == -1)
				{
					x_t++;
					a++;
				}
				else if (n == 1  && sw->czy_jest_Org(this->x - 1, this->y) == -1)
				{
					x_t--;
					a++;
				}
				else if (n == 2  && sw->czy_jest_Org(this->x, this->y + 1) == -1)
				{
					y_t++;
					a++;
				}
				else if (n == 3  && sw->czy_jest_Org(this->x, this->y - 1) == -1)
				{
					y_t--;
					a++;
				}
			}
			string nazwa;
			switch (this->no)
			{
			case wilk:
			{
				Wilk* w = new Wilk(x_t, y_t, *sw);
				this->sw->dodaj_organizm(w);
				nazwa = "wilk";
				break;
			}
			case owca:
			{
				Owca* o = new Owca(x_t, y_t, *sw);
				this->sw->dodaj_organizm(o);
				nazwa = "owca";
				break;
			}
			case lis:
			{
				Lis* l = new Lis(x_t, y_t, *sw);
				this->sw->dodaj_organizm(l);
				nazwa = "lis";
				break;
			}
			case zolw:
			{
				Zolw* z = new Zolw(x_t, y_t, *sw);
				this->sw->dodaj_organizm(z);
				nazwa = "zolw";
				break;
			}
			case antylopa:
			{
				Antylopa* a = new Antylopa(x_t, y_t, *sw);
				this->sw->dodaj_organizm(a);
				nazwa = "antylopa";
				break;
			}
			default:
				break;
			}
			string l1 = to_string(x_t);
			string l2 = to_string(y_t);
			string s = "Urodzil sie nowy organizm typu: " + nazwa + " na polu: " + l1 + "," + l2 ;
			sw->dodaj_info(s);
		}
		
	}
	else
	{
		if (sw->get_Org(k)->czyOdbilAtak(this) == false)
		{
			if (this->sila >= sw->get_Org(k)->Get_sila() && sw->get_Org(k)->smierc() == false)
			{

				this->x = x;
				this->y = y;
				string nazwa = this->str_nazwa();
				string nazwa2 = sw->get_Org(k)->str_nazwa();
				this->sila = this->sila + sw->get_Org(k)->boostStr();
				sw->usun(k);
				string l1 = to_string(x);
				string l2 = to_string(y);
				string s = nazwa + " zabil " + nazwa2 + " na polu: " + l1 + "," + l2;
				sw->dodaj_info(s);
			}
			else
			{
				int l = sw->czy_jest_Org(this->x, this->y);
				string nazwa = this->str_nazwa();
				string nazwa2 = sw->get_Org(k)->str_nazwa();
				string l1 = to_string(x);
				string l2 = to_string(y);
				string s = nazwa2 + " zabil " + nazwa + " na polu: " + l1 + "," + l2;
				sw->dodaj_info(s);
				sw->usun(l);
			}
		}

	}
}
Zwierze::~Zwierze()
{
}
