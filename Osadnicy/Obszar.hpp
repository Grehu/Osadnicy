#pragma once
#include "RysunekComponent.hpp"
#include "Pole.hpp"
#include "Osada.hpp"
#include "Port.hpp"
#include "Droga.hpp"


enum class Odmiana {
	nieprawidlowa,
	poleSurowcow,
	pustynia,
	morze,
	miejsceDostepne,
	miejsceNiedostepne
};
template <class typ>
struct Obszar{
	Vector2f pozycja = 0;
	RysunekComponent grafika = 0;
	Odmiana odmiana = Odmiana::nieprawidlowa;
	typ obiekt = 0;
};

