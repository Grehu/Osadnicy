#pragma once
#include <unordered_map>
#include <vector>
#include <SFML\Graphics.hpp>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace sf;

class DystrybutorTekstur {
protected:
	unordered_map<string, vector<Texture*>> magazyn;
public:
	DystrybutorTekstur();
	Texture * pobierzLosowaTeksture(string etykieta);
	Texture * pobierzKonkretnaTeksture(string etykieta, int numer);
	void dodajTeksture(string nazwaPliku, string etykieta);
};