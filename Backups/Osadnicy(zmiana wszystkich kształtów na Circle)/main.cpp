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

//#include <cstring>
//#include <map>

using namespace sf;
using namespace std;


int width = 800;
int height = 600;
int main() {
	RenderWindow oknoAplikacji(VideoMode(width, height, 32), "Osadnicy z Catanu", Style::Close);

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

	if (!teksturaMiasto.loadFromFile("city1.png")) { cout << "Blad ladowania tekstury miasta" << endl; }
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

	ConvexShape  lasKsztalt;
	CircleShape  wartoscKsztalt(32);
	ConvexShape  ramkaKsztalt;
	CircleShape  zlodziejKsztalt(32);
	RectangleShape drogaKsztalt(Vector2f(128, 16));
	CircleShape  miastoKsztalt(32);
	CircleShape  ramkaMiastaKsztalt(34);

	lasKsztalt.setPointCount(6);
	ramkaKsztalt.setPointCount(6);

	lasKsztalt.setPoint(0, sf::Vector2f(64, 20));
	lasKsztalt.setPoint(1, sf::Vector2f(192, 20));
	lasKsztalt.setPoint(2, sf::Vector2f(256, 128));
	lasKsztalt.setPoint(3, sf::Vector2f(192, 236));
	lasKsztalt.setPoint(4, sf::Vector2f(64, 236));
	lasKsztalt.setPoint(5, sf::Vector2f(0, 128));

	ramkaKsztalt.setPoint(0, sf::Vector2f(64, 20));
	ramkaKsztalt.setPoint(1, sf::Vector2f(192, 20));
	ramkaKsztalt.setPoint(2, sf::Vector2f(256, 128));
	ramkaKsztalt.setPoint(3, sf::Vector2f(192, 236));
	ramkaKsztalt.setPoint(4, sf::Vector2f(64, 236));
	ramkaKsztalt.setPoint(5, sf::Vector2f(0, 128));

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
	drogaKsztalt.setFillColor(Color(255, 0, 255, 200));
	

	miastoKsztalt.setTexture(wskTeksturaMiasto);
	ramkaMiastaKsztalt.setTexture(wskTeksturaRamkaMiasta);

	

	Vector2f polozenieD(128.0f, 128.0f);
	Vector2f polozenieM(256.0f, 256.0f);

	Vector2f pozycja1(0.0f, 0.0f);
	Vector2f pozycja2(256.0f, 0.0f);
	Vector2f pozycja3(128.0f, 128.0f);

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
	BudynekLeaf budynek;

	pole.ustawPozycje(polozenieD);
	pole.ustawKsztalt(lasKsztalt);

	ramka.ustawPozycje(polozenieD);
	ramka.ustawKsztalt(ramkaKsztalt);

	wartosc.nadajZlodziejowiGrafike(zlodziejKsztalt);
	wartosc.ustawPozycje(polozenieM);
	wartosc.ustawKsztalt(wartoscKsztalt);
	wartosc.przypiszText(text);

	kompozyt.ustawPole(pole);
	kompozyt.ustawRamke(ramka);
	kompozyt.ustawWartosc(wartosc);
	kompozyt.ustawPozycje(polozenieD);

	budynek.ustawKsztalt(miastoKsztalt);
	budynek.ustawPozycje(polozenieB);
	budynek.ustawKolorRamki(Color(255, 0, 255, 200));

	droga.ustawKsztalt(drogaKsztalt);
	droga.ustawPozycje(polozenieB);

	wartosc.ustawZlodzieja();
	
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
		//tu Twój kod
		oknoAplikacji.clear(Color::Black);
		kompozyt.ustawPozycje(pozycja1);
		kompozyt.rysuj(oknoAplikacji);
		kompozyt.ustawPozycje(pozycja2);
		kompozyt.rysuj(oknoAplikacji);
		kompozyt.ustawPozycje(pozycja3);
		kompozyt.rysuj(oknoAplikacji);
		//droga.rysuj(oknoAplikacji);
		//budynek.rysuj(oknoAplikacji);
		oknoAplikacji.display();
	}
	//system("PAUSE");
	return 0;
}