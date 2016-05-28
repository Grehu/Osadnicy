#pragma once
#include "Surowiec.hpp"
using namespace std;
class Pole {
private:
	int wartosc = 0;
	Surowiec surowiec;
	bool zlodziej = false;
public:
	
	void ustawSurowiec(Surowiec surowiec);
	void ustawWartosc(int wartosc);

	void ustawZlodzieja();
	void zdejmijZlodzieja();

	Surowiec rodzajSurowca();
	int zbierzSurowce(int ilosc, int wartosc);
};
