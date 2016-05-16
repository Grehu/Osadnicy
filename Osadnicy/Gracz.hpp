#pragma once
#include <unordered_map>
#include <vector>
#include "Osada.hpp"
#include "Droga.hpp"
#include "Port.hpp"

using namespace std;

class Gracz {
protected:
	static int liczbaGraczy;
	int ID;
	string kolor;
	unordered_map<string, int> surowce;
	unordered_map<string, int> kartyRozwoju;
	vector<Osada*> osady;
	vector<Droga*> drogi;
	/*vector<Port*> porty;*/
	
public:
	Gracz(string kolor);
	void zbierzSurowce(int wartosc);
	void dodajOsade(Osada * Osada);
	void dodajDroge(Droga * droga);
	
};

