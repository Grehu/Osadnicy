#pragma once
#include <SFML\Graphics.hpp>
#include "RysunekComponent.hpp"

using namespace sf;

class BudynekLeaf : public RysunekComponent {
protected:
	bool podswietlone;
	Color kolorWlasciciela;
	double rozjasnienie = 0.0f;
	Shape * zerowyStopien;
	Shape * pierwszyStopien;
	Shape * drugiStopien;
	int stopienRozwoju = 0;
public:
	void rysuj(RenderWindow & okno, Vector2f * przewijanie);
	void ustawKolorRamki(Color kolor);
	bool sprawdzPunkt(RenderWindow & okno);
	void wybierzObraz();
	void rozbuduj();
	void ustawGrafiki(Shape * grafika1, Shape * grafika2, Shape * grafika3);
	~BudynekLeaf();
};