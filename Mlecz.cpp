#include "Mlecz.h"
#include <iostream>


Mlecz::Mlecz()
{

}
Mlecz::Mlecz(int x, int y, Swiat& sw)
	:Roslina(x, y, sw)
{
	sila = 0;
	inicjatywa = 0;
	no = mlecz;
}
void Mlecz::akcja()
{
	int l = 0, a, b, c, d, e, i = 0;
	a = sw->czy_jest_Org(x + 1, y);
	b = sw->czy_jest_Org(x - 1, y);
	c = sw->czy_jest_Org(x, y + 1);
	d = sw->czy_jest_Org(x, y - 1);
	if (a != -1)
		l++;
	if (b != -1)
		l++;
	if (c != -1)
		l++;
	if (d != -1)
		l++;
	e = l;
	while (i < 3 && e == l)
	{
		l = 0;
		this->Roslina::akcja();
		a = sw->czy_jest_Org(x + 1, y);
		b = sw->czy_jest_Org(x - 1, y);
		c = sw->czy_jest_Org(x, y + 1);
		d = sw->czy_jest_Org(x, y - 1);
		if (a != -1)
			l++;
		else if (b != -1)
			l++;
		else if (c != -1)
			l++;
		else if (d != -1)
			l++;
		i++;
	}
}
void Mlecz::rysowanie()
{
	std::cout << "M";
}