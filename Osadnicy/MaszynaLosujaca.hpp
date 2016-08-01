#pragma once
#include <random>
#include <ctime>
#include <queue>

class MaszynaLosujaca {
private:
	static std::queue<int> calkowite;
public:
	static void inicjuj();
	static int pobierzCalkowita();
};