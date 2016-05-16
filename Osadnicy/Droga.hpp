#pragma once
#include "Osada.hpp"
class Droga {
protected:
	Osada * wezel1;
	Osada * wezel2;
	bool zbudowana = false;
public:
	void ustawWezly(Osada * osada1, Osada * osada2);
	void zbuduj();
	bool czyIstnieje();
};