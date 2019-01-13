#include "Barszcz_sosnowskiego.h"
#include <iostream>
Barszcz_sosnowskiego::Barszcz_sosnowskiego()
{

}
Barszcz_sosnowskiego::Barszcz_sosnowskiego(int x, int y, Swiat& sw)
	:Roslina(x, y, sw)
{
	sila = 10;
	inicjatywa = 0;
	no = barszcz_sosnowskiego;
}
bool Barszcz_sosnowskiego::smierc()
{
	return true;
}
void Barszcz_sosnowskiego::akcja()
{
	int a = -1, b = -1, c = -1, d = -1, e = -1, f = -1, g = -1, h = -1;
	if (x < sw->Get_s_x())
		a = sw->czy_jest_Org(x + 1, y);
	if (x > 0)
		b = sw->czy_jest_Org(x - 1, y);
	if (y < sw->Get_s_y())
		c = sw->czy_jest_Org(x, y + 1);
	if (y > 0)
		d = sw->czy_jest_Org(x, y - 1);
	if (x < sw->Get_s_x() && y < sw->Get_s_y())
		e = sw->czy_jest_Org(x + 1, y + 1);
	if (x > 0 && y > 0)
		f = sw->czy_jest_Org(x - 1, y - 1);
	if (y < sw->Get_s_y() && x > 0)
		g = sw->czy_jest_Org(x - 1, y + 1);
	if (y > 0 && x < sw->Get_s_x())
		h = sw->czy_jest_Org(x + 1, y - 1);
	if (a != -1)
		sw->usun(a);
	if (b != -1)
		sw->usun(b);
	if (c != -1)
		sw->usun(c);
	if (d != -1)
		sw->usun(d);
	if (e != -1)
		sw->usun(e);
	if (f != -1)
		sw->usun(f);
	if (g != -1)
		sw->usun(g);
	if (h != -1)
		sw->usun(h);
}
void Barszcz_sosnowskiego::rysowanie()
{
	std::cout << "B";
}
