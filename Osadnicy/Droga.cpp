#include "Droga.hpp"

void Droga::ustawWezly(Osada * osada1, Osada * osada2)
{
	wezel1 = osada1;
	wezel2 = osada2;
}

void Droga::zbuduj()
{
	zbudowana = true;
}

bool Droga::czyIstnieje()
{
	return zbudowana;
}
