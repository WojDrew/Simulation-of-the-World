#include "Swiat.h"
#include "Organizm.h"
#include <initializer_list>
#include <fstream>
#include <algorithm>
#include <string>
#include <iostream>
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
using namespace std;

Swiat::Swiat()
{
}
Swiat::Swiat(int lo, int x, int y)
{
	liczba_organizmow = lo;
	this->size_x = x;
	this->size_y = y;
}

void Swiat::dodaj_organizm(Organizm* orga)
{
	org.push_back(orga);
}

Organizm* Swiat::get_Org(int i)
{
	return org[i];
}

void Swiat::rysuj_Swiat()
{
	system("cls");
	cout << "Wojciech Drewek 171838"<<endl;
	for (int i = 0; i <= size_y+1; i++)
	{
		for (int j = 0; j <= size_x+1; j++)
		{
			int k = czy_jest_Org(j, i);
			if (i == 0 || i == size_y + 1 || j == 0 || j == size_x + 1)
				cout << "#";
			else if (k > -1)
			{
				org[k]->rysowanie();
			}
			else
				cout << " ";
		}
		cout << endl;
	}
		for (list<string>::iterator i = inf.begin(); i != inf.end(); i++)
			cout << *i << endl;
		inf.clear();
}

void Swiat::wykonajTure()
{
	sort(org.begin(), org.end(), [](Organizm* org1, Organizm* org2) {return org1->Get_Wiek() > org2->Get_Wiek();  });
	sort(org.begin(), org.end(), [](Organizm* org1, Organizm* org2) {return org1->Get_Inicjatywa() > org2->Get_Inicjatywa();  });
	liczba_organizmow = org.size();
	for (int i = 0; i < liczba_organizmow; i++)
	{
		org[i]->akcja();
		if (liczba_organizmow > org.size())
			liczba_organizmow = org.size();
	}
}

void Swiat::dodaj_info(string s)
{
	inf.push_back(s);
}

int Swiat::czy_jest_Org(int x,int y)
{
	for (int i = 0; i < org.size(); i++)
			if (org[i]->Get_x() == x && org[i]->Get_y() == y)
				return i;
	return -1;
}

Organizm* Swiat::operator[](int i)
{
	return org[i];
}

int Swiat::get_Liczba_Organizmow()
{
	return liczba_organizmow;
}

void Swiat::usun(int k)
{
	if (k < org.size())
	{
		delete org[k];
		std::vector<Organizm*>::iterator iter = std::find(org.begin(), org.end(), org[k]);
		org.erase(iter);
	}
}

int Swiat::Get_s_x()
{
	return size_x;
}
int Swiat::Get_s_y()
{
	return size_y;
}

void Swiat::zapisz()
{
	string nazwa;
	cout << "Podaj nazwe";
	cin >> nazwa;
	fstream plik;
	plik.open(nazwa+".txt", ios::out);
	int a = org.size();
	plik << a << endl;
	plik << size_x << endl;
	plik << size_y << endl;
	for (int i = 0; i < org.size(); i++)
	{
		plik << "#" << org[i]->str_nazwa() << "#";
		plik << org[i]->Get_x() << "#";
		plik << org[i]->Get_y() << "#";
		plik << org[i]->Get_sila() << "#";
		plik << org[i]->Get_Inicjatywa() << "#" << endl;
	}
	plik.close();
}

void Swiat::wczytaj()
{
	org.clear();
	string nazwa_pliku;
	cout << "Podaj nazwe";
	cin >> nazwa_pliku;
	fstream plik;
	plik.open(nazwa_pliku + ".txt", ios::in);
	int l_o, x, y;
	plik >> l_o;
	plik >> x;
	plik >> y;
	this->size_x = x;
	this->size_y = y;
	for (int i = 0; i < l_o; i++)
	{
		string nazwa, x_s, y_s, sila, inic;
		string dane;
		plik >> dane;
		int w = 0, pop;
		for (int j = 0; j < dane.size(); j++)
		{
			if (dane[j] == '#' && w == 0)
				w++;
			else if (dane[j] == '#' && w == 1)
			{
				for (int k = 1; k < j; k++)
				{
					nazwa.push_back(dane[k]);
					pop = k + 2;
				}
				w++;
			}
			else if (dane[j] == '#' && w == 2)
			{
				for (int k = pop; k < j; k++)
				{
					x_s.push_back(dane[k]);
					pop = k + 2;
				}
				w++;
			}
			else if (dane[j] == '#' && w == 3)
			{
				for (int k = pop; k < j; k++)
				{
					y_s.push_back(dane[k]);
					pop = k + 2;
				}
				w++;
			}
			else if (dane[j] == '#' && w == 4)
			{
				for (int k = pop; k < j; k++)
				{
					sila.push_back(dane[k]);
					pop = k + 2;
				}
				w++;
			}
			else if (dane[j] == '#' && w == 5)
			{
				for (int k = pop; k < j; k++)
				{
					inic.push_back(dane[k]);
					pop = k + 2;
				}
				w++;
			}
		}
		int x_t, y_t, sil, ini;
		x_t = stoi(x_s);
		y_t = stoi(y_s);
		sil = stoi(sila);
		ini = stoi(inic);
		if(nazwa == "wilk")
		{
			Wilk* w = new Wilk(x_t, y_t, *this);
			w->Set_sila(sil);
			w->Set_ini(ini);
			this->dodaj_organizm(w);
		}
		else if (nazwa == "owca")
		{
			Owca* o = new Owca(x_t, y_t, *this);
			o->Set_sila(sil);
			o->Set_ini(ini);
			this->dodaj_organizm(o);
		}
		else if (nazwa == "lis")
		{
			Lis* l = new Lis(x_t, y_t, *this);
			l->Set_sila(sil);
			l->Set_ini(ini);
			this->dodaj_organizm(l);
		}
		else if (nazwa == "zolw")
		{
			Zolw* z = new Zolw(x_t, y_t, *this);
			z->Set_sila(sil);
			z->Set_ini(ini);
			this->dodaj_organizm(z);
		}
		else if (nazwa == "antylopa")
		{
			Antylopa* a = new Antylopa(x_t, y_t, *this);
			a->Set_sila(sil);
			a->Set_ini(ini);
			this->dodaj_organizm(a);
		}
		else if (nazwa == "trawa")
		{
			Trawa* t = new Trawa(x_t, y_t, *this);
			t->Set_sila(sil);
			t->Set_ini(ini);
			this->dodaj_organizm(t);
		}
		else if (nazwa == "mlecz")
		{
			Mlecz* m = new Mlecz(x_t, y_t, *this);
			m->Set_sila(sil);
			m->Set_ini(ini);
			this->dodaj_organizm(m);
		}
		else if (nazwa == "guarana")
		{
			Guarana* g = new Guarana(x_t, y_t, *this);
			g->Set_sila(sil);
			g->Set_ini(ini);
			this->dodaj_organizm(g);
		}
		else if (nazwa == "wilcze_jagody")
		{
			Wilcze_jagody* j = new Wilcze_jagody(x_t, y_t, *this);
			j->Set_sila(sil);
			j->Set_ini(ini);
			this->dodaj_organizm(j);
		}
		else if (nazwa == "barszcz_sosnowskiego")
		{
			Barszcz_sosnowskiego* b = new Barszcz_sosnowskiego(x_t, y_t, *this);
			b->Set_sila(sil);
			b->Set_ini(ini);
			this->dodaj_organizm(b);
		}
		else if (nazwa == "czlowiek")
		{
			Czlowiek* c = new Czlowiek(x_t, y_t, *this);
			c->Set_sila(sil);
			c->Set_ini(ini);
			this->dodaj_organizm(c);
		}
		
	}


	plik.close();
}

Swiat::~Swiat()
{
	for (int i = 0; i < org.size(); i++)
		delete org[i];
}
