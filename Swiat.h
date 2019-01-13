#pragma once
#include <initializer_list>
#include <vector>
#include <list>
using namespace std;
class Organizm;


class Swiat
{
	int size_x, size_y, liczba_organizmow;
	vector <Organizm*> org;
	list <string> inf;
public:
	Swiat();
	Swiat(int,int,int);
	void dodaj_organizm(Organizm* orga);
	void rysuj_Swiat();
	void wykonajTure();
	int czy_jest_Org(int x,int y);
	Organizm* operator[](int i);
	Organizm* get_Org(int i);
	int get_Liczba_Organizmow();
	void usun(int k);
	void dodaj_info(string s);
	int Get_s_x();
	int Get_s_y();
	void zapisz();
	void wczytaj();
	~Swiat();
};

