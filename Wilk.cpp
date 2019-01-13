#include "Wilk.h"
#include <iostream>
Wilk::Wilk()
{

}
Wilk::Wilk(int x, int y, Swiat& sw)
	:Zwierze(x, y, sw)
{
	sila = 9;
	inicjatywa = 5;
	no = wilk;
}
void Wilk::rysowanie()
{
	std::cout << "W";
}
