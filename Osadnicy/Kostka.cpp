#include "Kostka.hpp"

Kostka::Kostka(int iloscScian)
{
	this->iloscScian = iloscScian;
	srand(time(NULL));
}

int Kostka::policzSciany()
{
	return iloscScian;
}

int Kostka::losujLiczbe() const
{
	return rand()%iloscScian+1;
}
