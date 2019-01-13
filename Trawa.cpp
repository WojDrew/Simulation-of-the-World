#include "Trawa.h"
#include <iostream>
Trawa::Trawa()
{

}
Trawa::Trawa(int x, int y, Swiat& sw)
	:Roslina(x, y, sw)
{
	sila = 0;
	inicjatywa = 0;
	no = trawa;
}
void Trawa::rysowanie()
{
	std::cout << "T";
}

