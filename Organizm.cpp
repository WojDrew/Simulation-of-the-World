#include "Organizm.h"
#include "Swiat.h"
using namespace std;


Organizm::Organizm()
{

}

Organizm::Organizm(int x, int y, Swiat& sw)
{
	this->x = x;
	this->y = y;
	this->sw = &sw;
	wiek = 0;
}

nazwa_Organizmu Organizm::nazwa()
{
	return no;
}

int Organizm::boostStr()
{
	return 0;
}

bool Organizm::smierc()
{
	return false;
}

bool Organizm::kolizja_obronna(Organizm* o)
{
	return false;
}

bool Organizm::wokol()
{
	if ((x + 1 <= sw->Get_s_x() && sw->czy_jest_Org(x + 1, y) == -1) || (x - 1 > 0 && sw->czy_jest_Org(x - 1, y) == -1) || (y + 1 <= sw->Get_s_y()  && sw->czy_jest_Org(x, y + 1) == -1) || (y - 1 > 0 && sw->czy_jest_Org(x, y - 1) == -1))
	{
		return true;
	}
	else
		return false;
}

int Organizm::Get_Wiek()
{
	return this->wiek;
}

void Organizm::losuj(int& x_t, int& y_t)
{
	int a = 0;
	while (a == 0)
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
	}
}

string Organizm::str_nazwa()
{
	switch (this->no)
	{
	case wilk:
		return "wilk";
		break;
	case owca:
		return "owca";
		break;
	case lis:
		return "lis";
		break;
	case zolw:
		return "zolw";
		break;
	case antylopa:
		return "antylopa";
		break;
	case trawa:
		return "trawa";
		break;
	case guarana:
		return "guarana";
		break;
	case mlecz:
		return "mlecz";
		break;
	case barszcz_sosnowskiego:
		return "barszcz_sosnowskiego";
		break;
	case wilcze_jagody:
		return "wilcze_jagody";
		break;
	case czlowiek:
		return "czlowiek";
		break;
	default:
		break;
	}
}

int Organizm::Get_x()
{
	return x;
}
bool Organizm::czyOdbilAtak(Organizm* o)
{
	return false;
}

int Organizm::Get_y()
{
	return y;
}

int Organizm::Get_sila()
{
	return this->sila;
}

int Organizm::Get_Inicjatywa()
{
	return inicjatywa;
}

Organizm::~Organizm()
{
}

void Organizm::Set_sila(int s)
{
	this->sila = s;
}
void Organizm::Set_ini(int i)
{
	this->inicjatywa = i;
}
