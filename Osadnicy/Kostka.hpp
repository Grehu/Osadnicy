#pragma once
#include <SFML\Graphics.hpp>
#include <random>
#include <ctime>

class Kostka {
private:
	int iloscScian;
public:
	Kostka(int iloscScian);
	int policzSciany();
	int losujLiczbe() const;
};
