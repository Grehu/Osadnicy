#include "MaszynaLosujaca.hpp"

std::queue<int> MaszynaLosujaca::calkowite;

void MaszynaLosujaca::inicjuj()
{
	srand(time(NULL));
}

int MaszynaLosujaca::pobierzCalkowita()
{
	if (calkowite.size() < 10) {
		srand(time(NULL));
		for (int i = 0; i < 50; i++) {
			calkowite.push(rand());
		}
	}
	int temp = calkowite.front();
	calkowite.pop();
	return temp;
}
