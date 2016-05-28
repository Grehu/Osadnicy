#include <iostream>
#include <cmath>
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "RysunekComponent.hpp"
#include "RamkaLeaf.hpp"
#include "PoleLeaf.hpp"
#include "PoleWartosciLeaf.hpp"
#include "RysunekComposite.hpp"
#include "BudynekLeaf.hpp"
#include "PortLeaf.hpp"
#include "Stale.hpp"

#include "DystrybutorWartosci.hpp"

#include "Plansza.hpp"
#include "PlanszaBuilder.hpp"
#include "LosowaPlanszaBuilder.hpp"

#include "Testy.hpp"

//#include <cstring>
//#include <map>

using namespace sf;
using namespace std;


int szerokosc = 1200;
int wysokosc = 600;
int main() {
	RenderWindow oknoAplikacji(VideoMode(szerokosc, wysokosc, 32), "Osadnicy z Catanu", Style::Close);

	Texture teksturaLas;
	Texture teksturaWartosc;
	Texture teksturaRamka;
	Texture teksturaZlodziej;

	Texture teksturaDroga;

	Texture teksturaMiasto;
	Texture teksturaRamkaMiasta;

	if (!teksturaLas.loadFromFile("lumber0.png")) { cout << "Blad ladowania tekstury lasu" << endl; }
	else { cout << "Tekstura zaladowana!" << endl; }
	if (!teksturaWartosc.loadFromFile("value0.png")) { cout << "Blad ladowania tekstury wartosci" << endl; }
	else { cout << "Tekstura zaladowana!" << endl; }
	if (!teksturaRamka.loadFromFile("board0.png")) { cout << "Blad ladowania tekstury ramki" << endl; }
	else { cout << "Tekstura zaladowana!" << endl; }
	if (!teksturaZlodziej.loadFromFile("thief0.png")) { cout << "Blad ladowania tekstury zlodzieja" << endl; }
	else { cout << "Tekstura zaladowana!" << endl; }

	if (!teksturaDroga.loadFromFile("road.png")) { cout << "Blad ladowania tekstury drogi" << endl; }
	else { cout << "Tekstura zaladowana!" << endl; }

	if (!teksturaMiasto.loadFromFile("city3.png")) { cout << "Blad ladowania tekstury miasta" << endl; }
	else { cout << "Tekstura zaladowana!" << endl; }
	if (!teksturaRamkaMiasta.loadFromFile("board1.png")) { cout << "Blad ladowania tekstury ramki miasta" << endl; }
	else { cout << "Tekstura zaladowana!" << endl; }

	teksturaLas.setSmooth(true);
	teksturaRamka.setSmooth(true);
	teksturaWartosc.setSmooth(true);
	teksturaZlodziej.setSmooth(true);

	teksturaDroga.setSmooth(true);
	teksturaDroga.setRepeated(true);

	teksturaMiasto.setSmooth(true);
	teksturaRamkaMiasta.setSmooth(true);

	CircleShape  lasKsztalt(128, 6);
	CircleShape  wartoscKsztalt(32);
	CircleShape  ramkaKsztalt(128, 6);
	CircleShape  zlodziejKsztalt(32);
	RectangleShape drogaKsztalt(Vector2f(128, 16));
	CircleShape  miastoKsztalt(32);
	CircleShape  ramkaMiastaKsztalt(34);

	lasKsztalt.setPointCount(6);
	ramkaKsztalt.setPointCount(6);


	Texture * wskTeksturaLas = &teksturaLas;
	Texture * wskTeksturaWartosc = &teksturaWartosc;
	Texture * wskTeksturaRamka = &teksturaRamka;
	Texture * wskTeksturaZlodziej = &teksturaZlodziej;

	Texture * wskTeksturaDroga = &teksturaDroga;

	Texture * wskTeksturaMiasto = &teksturaMiasto;
	Texture * wskTeksturaRamkaMiasta = &teksturaRamkaMiasta;


	lasKsztalt.setTexture(wskTeksturaLas);
	wartoscKsztalt.setTexture(wskTeksturaWartosc);
	ramkaKsztalt.setTexture(wskTeksturaRamka);
	zlodziejKsztalt.setTexture(wskTeksturaZlodziej);

	drogaKsztalt.setTexture(wskTeksturaDroga);
	drogaKsztalt.setFillColor(Color(150, 0, 150, 100));
	

	miastoKsztalt.setTexture(wskTeksturaMiasto);
	ramkaMiastaKsztalt.setTexture(wskTeksturaRamkaMiasta);

	

	Vector2f polozenieD(128.0f, 128.0f);
	Vector2f polozenieM(128.0f, 128.0f);

	float przesunieciePodstawowe_XR1 = 224.0f;
	float przesunieciePodstawowe_YR1 = 0.0f;

	float przesuniecieRzedowe_X = 112.0f;
	float przesuniecieRzedowe_Y = 192.0f;

	float drugiRzadX = 128.0f - 16.00f;
	float przesuniecieY = 256.0f - 64.0f;
	float przesuniecieX = 256.0f - 32.00f;

	Vector2f pozycja1(0.0f, 0.0f); //= (PRZESUNIECIE_X*0.0) + (PRZESUNIECIE_Y*0.0) + (MODYFIKATOR_RZEDU_NIEPARZYSTEGO * (0 % 2));
	Vector2f pozycja2(256.0f - 32.00f, 0.0f);
	Vector2f pozycja3(128.0f - 16.00f, 256.0f - 64.0f);
	Vector2f pozycja4(256.0f - 48.00f, 256.0f - 73.5f - 16.0f);

	Vector2f pozycja5(przesuniecieX * 2, 0.0f);
	Vector2f pozycja6(przesuniecieX * 2 + drugiRzadX, przesuniecieY);
	Vector2f pozycja7(0.0f, przesuniecieY * 2);
	Vector2f pozycja8(przesuniecieRzedowe_X, przesuniecieRzedowe_Y + przesuniecieY * 2);

	//Vector2f pozycja5();

	Vector2f polozenieB(0.0f, 0.0f);

	lasKsztalt.setPosition(polozenieD);

	Font font;
	font.loadFromFile("Squares Bold Free.otf");
	Text text;
	text.setFont(font);
	text.setCharacterSize(56);
	text.setColor(Color(0, 0, 0));
	text.setString("8");

	//RysunekComponent (* rysunek)[4];

	PoleLeaf pole;
	RamkaLeaf ramka;
	PoleWartosciLeaf wartosc;
	RysunekComposite kompozyt;
	RysunekComponent droga;
	PortLeaf budynek;

	pole.ustawPozycje(&polozenieD);
	pole.ustawKsztalt(lasKsztalt);

	ramka.ustawPozycje(&polozenieD);
	ramka.ustawKsztalt(ramkaKsztalt);

	wartosc.nadajZlodziejowiGrafike(zlodziejKsztalt);
	wartosc.ustawPozycje(&polozenieM);
	wartosc.ustawKsztalt(wartoscKsztalt);
	wartosc.przypiszText(text);

	kompozyt.ustawPole(pole);
	kompozyt.ustawRamke(ramka);
	kompozyt.ustawWartosc(wartosc);
	kompozyt.ustawPozycje(&polozenieD);

	budynek.ustawKsztalt(miastoKsztalt);
	budynek.ustawSurowiec(zlodziejKsztalt);
	budynek.ustawPozycje(&polozenieB);
	budynek.ustawKolory(&Color(255, 0, 0, 0), &Color(255, 255, 255, 0));
	//budynek.ustawKolorRamki(Color(200, 0, 200, 200));

	droga.ustawKsztalt(drogaKsztalt);
	droga.ustawPozycje(&polozenieB);

	//wartosc.ustawZlodzieja();
	
	Vector2f przewijanie(0.0f, 0.0f);
	Vector2f krok(0.1f, 0.1f);
	bool wzrost = true;

	Test test;
	//test.testPrzyporzadkowaniaPortu();
	test.testPrzyporzadkowaniaOsady();
	while (oknoAplikacji.isOpen())
	{

		Event zdarzenie;

		while (oknoAplikacji.pollEvent(zdarzenie))
		{
			if (zdarzenie.type == sf::Event::Closed)
			{
				//tu np. zapisanie stanu gry
				oknoAplikacji.close();
			}
		}


		/*if (przewijanie.x > 256.0f || przewijanie.y > 256.0f) { wzrost = false; }
		if (przewijanie.x < 1.0f || przewijanie.y < 1.0f) { wzrost = true; }
		if (wzrost) { przewijanie += krok; }
		else { przewijanie -= krok; }*/
		//tu Twój kod
		oknoAplikacji.clear(Color::Black);
		/*kompozyt.ustawPozycje(&pozycja1);
		kompozyt.rysuj(oknoAplikacji, &przewijanie);
		kompozyt.ustawPozycje(&pozycja2);
		kompozyt.rysuj(oknoAplikacji, &przewijanie);
		kompozyt.ustawPozycje(&pozycja3);
		kompozyt.rysuj(oknoAplikacji, &przewijanie);
		kompozyt.ustawPozycje(&pozycja5);
		kompozyt.rysuj(oknoAplikacji, &przewijanie);
		kompozyt.ustawPozycje(&pozycja6);
		kompozyt.rysuj(oknoAplikacji, &przewijanie);
		kompozyt.ustawPozycje(&pozycja7);
		kompozyt.rysuj(oknoAplikacji, &przewijanie);
		kompozyt.ustawPozycje(&pozycja8);
		kompozyt.rysuj(oknoAplikacji, &przewijanie);
		*/
		//droga.rysuj(oknoAplikacji);
		//budynek.ustawPozycje(&pozycja4);
		//budynek.rysuj(oknoAplikacji, &przewijanie);
		oknoAplikacji.display();
	}
	//system("PAUSE");
	return 0;
}