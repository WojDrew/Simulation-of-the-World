#include "Owca.h"
#include <iostream>

Owca::Owca()
{

}
Owca::Owca(int x, int y, Swiat& sw)
	:Zwierze(x, y, sw)
{
	sila = 4;
	inicjatywa = 4;
	no = owca;
}
void Owca::rysowanie()
{
	std::cout << "O";
}
