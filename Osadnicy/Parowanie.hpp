#pragma once
#include "Koordynaty.hpp"
///UWAGA - sprawdzanie poprawno�ci algorytm�w w metodach tej klasy jest trudne. Zalecane skorzystanie z pliku hexy.png znajduj�cego si� w katalogu g��wnym projektu
static class Parowanie {
public:
	static Koordynaty osadaDlaDrogi_1(const Koordynaty & kDrogi);
	static Koordynaty osadaDlaDrogi_2(const Koordynaty & kDrogi);
	static int orientacjaDlaDrogi(const Koordynaty & kDrogi);
	static Koordynaty poleDlaOsady_1(const Koordynaty & kOsady);
	static Koordynaty poleDlaOsady_2(const Koordynaty & kOsady);
	static Koordynaty poleDlaOsady_3(const Koordynaty & kOsady);
	//static Koordynaty poleDlaOsady(const Koordynaty & kDrogi);
};