#pragma once
#include <SFML\Graphics.hpp>
#include <random>
#include <ctime>
#include <string>


class Kostka {
private:
	int iloscScian;
public:
	Kostka(int iloscScian);
	int policzSciany();
	int losujLiczbe() const;
};

/*int operator +(const Kostka & k1, const Kostka & k2) {
	return k1.losujLiczbe() + k2.losujLiczbe();
}*/
