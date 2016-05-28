#pragma once
#include <unordered_map>
#include <vector>
#include <SFML\Graphics\Font.hpp>
#include <random>
#include <ctime>
#include "PrzeznaczenieFontu.hpp"
using namespace std;
using namespace sf;

class DystrybutorCzcionek {
protected:
	unordered_map<PrzeznaczenieFontu, vector<Font>> magazyn;
public:
	DystrybutorCzcionek();
	Font pobierzLosowaCzcionke(PrzeznaczenieFontu etykieta);
	Font pobierzKonkretnaCzcionke(PrzeznaczenieFontu etykieta, int numer);
	void dodajCzcionke(string nazwaPliku, PrzeznaczenieFontu etykieta);
};