#pragma once
#include "Swiat.h"
class Swiat;
enum nazwa_Organizmu
{
	wilk = 0,
	owca = 1,
	lis = 2,
	zolw = 3,
	antylopa = 4,
	trawa = 5,
	mlecz = 6,
	guarana = 7,
	wilcze_jagody = 8,
	barszcz_sosnowskiego = 9,
	czlowiek = 10
};

class Organizm
{
protected:
	int sila;
	int inicjatywa;
	int x, y;
	int wiek;
	Swiat *sw;
	nazwa_Organizmu no;
public:
	Organizm();
	Organizm(int, int, Swiat&);
	nazwa_Organizmu nazwa();
	virtual bool czyOdbilAtak(Organizm* o);
	virtual int boostStr();
	virtual bool smierc();
	virtual void rysowanie() = 0;
	virtual void akcja() = 0;
	virtual void kolizja(int x, int y) = 0;
	virtual bool kolizja_obronna(Organizm* o);
	bool wokol();
	string str_nazwa();
	void losuj(int& x, int& y);
	int Get_x();
	int Get_y();
	int Get_Inicjatywa();
	int Get_Wiek();
	int Get_sila();
	void Set_sila(int s);
	void Set_ini(int i);
	~Organizm();
};

