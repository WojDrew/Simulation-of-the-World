#include "Guarana.h"
#include <iostream>


Guarana::Guarana()
{

}
Guarana::Guarana(int x, int y, Swiat& sw)
	:Roslina(x, y, sw)
{
	sila = 0;
	inicjatywa = 0;
	no = guarana;
}
int Guarana::boostStr()
{
	return 3;
}
void Guarana::rysowanie()
{
	std::cout << "G";
}
