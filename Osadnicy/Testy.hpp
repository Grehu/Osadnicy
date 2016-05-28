#pragma once
#include "Koordynaty.hpp"
#include "Parowanie.hpp"
#include <iostream>

class Test {
private:
	void porownaj(Koordynaty port, Koordynaty poprawne1, Koordynaty poprawne2);
	void porownaj(Koordynaty osada, Koordynaty poprawne1, Koordynaty poprawne2, Koordynaty poprawne3);
public:
	void testPrzyporzadkowaniaPortu();
	void testPrzyporzadkowaniaOsady();

};