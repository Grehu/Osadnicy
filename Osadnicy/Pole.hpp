#pragma once
#include <string>
using namespace std;
class Pole {
private:
	int wartosc = 0;
	string surowiec;
	bool zlodziej = false;
public:
	
	void ustawSurowiec(string surowiec);
	void ustawWartosc(int wartosc);

	void ustawZlodzieja();
	void zdejmijZlodzieja();

	string rodzajSurowca();
	int zbierzSurowce(int ilosc, int wartosc);
};
