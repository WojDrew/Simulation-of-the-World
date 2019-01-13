#include "Wilcze_jagody.h"
#include <iostream>

Wilcze_jagody::Wilcze_jagody()
{

}
Wilcze_jagody::Wilcze_jagody(int x, int y, Swiat& sw)
	:Roslina(x, y, sw)
{
	sila = 99;
	inicjatywa = 0;
	no = wilcze_jagody;
}
bool Wilcze_jagody::smierc()
{
	return true;
}
void Wilcze_jagody::rysowanie()
{
	std::cout << "J";
}

