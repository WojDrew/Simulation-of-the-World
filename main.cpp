#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include "Swiat.h"
#include "Organizm.h"
#include "Zwierze.h"
#include "Roslina.h"
#include "Wilk.h"
#include "Owca.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Czlowiek.h"
#include "Trawa.h"
#include "MLecz.h"
#include "Guarana.h"
#include "Wilcze_jagody.h"
#include "Barszcz_sosnowskiego.h"
#define WSP_ORG 3

using namespace std;

void stworzSwiat(Swiat& s);


int main()
{
	srand(time(NULL));
	char c = 'z';
	int x = 6, y = 6, n;
	while (x*y < 49)
	{
		cin >> x >> y;
		if (x*y < 49)
			cout << "Za maly rozmiar"<< endl;
	}
	n = (x*y / 10)*WSP_ORG;
	Swiat s(n,x,y);
	stworzSwiat(s);

	while (c != 'q')
	{
		s.rysuj_Swiat();
		
		c = _getch();
		if (c == 's')
			s.zapisz();
		else if (c == 'l')
			s.wczytaj();
		s.wykonajTure();
	}

	
	return 0;
}

void stworzSwiat(Swiat& s)
{
	int x = 1, y = 1 ;
	srand(time(NULL));
	int n = s.get_Liczba_Organizmow()/11;
	for (int i = 0; i < s.get_Liczba_Organizmow()-1; i++)
	{
		if (i < n)
		{
			while (s.czy_jest_Org(x, y) != -1)
			{
				x = rand() % s.Get_s_x() + 1;
				y = rand() % s.Get_s_y() + 1;
			}
			Wilk* w = new Wilk(x, y, s);
			s.dodaj_organizm(w);
		}
		else if(i < n*2)
		{
			while (s.czy_jest_Org(x, y) != -1)
			{
				x = rand() % s.Get_s_x() + 1;
				y = rand() % s.Get_s_y() + 1;
			}
			Owca* o = new Owca(x, y, s);
			s.dodaj_organizm(o);
		}
		else if (i < n * 3)
		{
			while (s.czy_jest_Org(x, y) != -1)
			{
				x = rand() % s.Get_s_x() + 1;
				y = rand() % s.Get_s_y() + 1;
			}
			Lis* l = new Lis(x, y, s);
			s.dodaj_organizm(l);
		}
		else if (i < n * 4)
		{
			while (s.czy_jest_Org(x, y) != -1)
			{
				x = rand() % s.Get_s_x() + 1;
				y = rand() % s.Get_s_y() + 1;
			}
			Zolw* z = new Zolw(x, y, s);
			s.dodaj_organizm(z);
		}
		else if (i < n * 5)
		{
			while (s.czy_jest_Org(x, y) != -1)
			{
				x = rand() % s.Get_s_x() + 1;
				y = rand() % s.Get_s_y() + 1;
			}
			Antylopa* a = new Antylopa(x, y, s);
			s.dodaj_organizm(a);
		}
		else if (i < n * 6)
		{
			while (s.czy_jest_Org(x, y) != -1)
			{
				x = rand() % s.Get_s_x() + 1;
				y = rand() % s.Get_s_y() + 1;
			}
			Barszcz_sosnowskiego* b = new Barszcz_sosnowskiego(x, y, s);
			s.dodaj_organizm(b);
		}
		else if (i < n * 7)
		{
			while (s.czy_jest_Org(x, y) != -1)
			{
				x = rand() % s.Get_s_x() + 1;
				y = rand() % s.Get_s_y() + 1;
			}
			Mlecz* m = new Mlecz(x, y, s);
			s.dodaj_organizm(m);
		}
		else if (i < n * 8)
		{
			while (s.czy_jest_Org(x, y) != -1)
			{
				x = rand() % s.Get_s_x() + 1;
				y = rand() % s.Get_s_y() + 1;
			}
			Guarana* g = new Guarana(x, y, s);
			s.dodaj_organizm(g);
		}
		else if (i < n * 9)
		{
			while (s.czy_jest_Org(x, y) != -1)
			{
				x = rand() % s.Get_s_x() + 1;
				y = rand() % s.Get_s_y() + 1;
			}
			Wilcze_jagody* j = new Wilcze_jagody(x, y, s);
			s.dodaj_organizm(j);
		}
		else 
		{
			while (s.czy_jest_Org(x, y) != -1)
			{
				x = rand() % s.Get_s_x() + 1;
				y = rand() % s.Get_s_y() + 1;
			}
			Trawa* o = new Trawa(x, y, s);
			s.dodaj_organizm(o);
		}

	}
	while (s.czy_jest_Org(x, y) != -1)
	{
		x = rand() % s.Get_s_x() + 1;
		y = rand() % s.Get_s_y() + 1;
	}
	Czlowiek* o = new Czlowiek(x, y, s);
	s.dodaj_organizm(o);
}