#pragma once
#include <unordered_map>
#include <vector>
#include <SFML\Graphics.hpp>
#include <random>
#include <ctime>
#include "Etykieta.hpp"
using namespace std;
using namespace sf;

class DystrybutorTekstur {
protected:
	unordered_map<Etykieta, vector<Texture*>> magazyn;
public:
	DystrybutorTekstur();
	Texture * pobierzLosowaTeksture(Etykieta etykieta);
	Texture * pobierzKonkretnaTeksture(Etykieta etykieta, int numer);
	void dodajTeksture(string nazwaPliku, Etykieta etykieta);
};