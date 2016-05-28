#pragma once
#include <unordered_map>
#include <vector>
#include "Osada.hpp"
#include "Droga.hpp"
#include "Port.hpp"
#include "Rozwoj.hpp"

using namespace std;

class Gracz {
protected:
	static int liczbaGraczy;
	int ID;
	string kolor;
	unordered_map<Surowiec, int> surowce;
	unordered_map<Rozwoj, int> kartyRozwoju;
	vector<Osada*> osady;
	vector<Droga*> drogi;
	/*vector<Port*> porty;*/
	
public:
	Gracz(string kolor);
	void zbierzSurowce(int wartosc);
	void dodajOsade(Osada * Osada);
	void dodajDroge(Droga * droga);
	
};

