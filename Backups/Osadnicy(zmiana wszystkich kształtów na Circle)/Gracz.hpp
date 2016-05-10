#pragma once
#include <unordered_map>
#include <list>

using namespace std;

class Gracz {
protected:
	static int liczbaGraczy;
	int ID;
	string kolor;
	unordered_map<string, int> surowce;
	unordered_map<string, int> kartyRozwoju;
	//list<Budynek*> budynki;
	//list<Droga*> drogi;
	//list<Port*> porty;
	

	Gracz(string kolor);
};

