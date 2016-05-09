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

	if (!teksturaLas.loadFromFile("lumber0.png")) { cout << "Blad ladowania tekstury lasu" << endl; }
	else { cout << "Tekstura zaladowana!" << endl; }
	if (!teksturaWartosc.loadFromFile("value0.png")) { cout << "Blad ladowania tekstury wartosci" << endl; }
	else { cout << "Tekstura zaladowana!" << endl; }
	if (!teksturaRamka.loadFromFile("board0.png")) { cout << "Blad ladowania tekstury ramki" << endl; }
	else { cout << "Tekstura zaladowana!" << endl; }
	if (!teksturaZlodziej.loadFromFile("thief0.png")) { cout << "Blad ladowania tekstury zlodzieja" << endl; }
	else { cout << "Tekstura zaladowana!" << endl; }

	teksturaLas.setSmooth(true);
	teksturaRamka.setSmooth(true);
	teksturaWartosc.setSmooth(true);
	teksturaZlodziej.setSmooth(true);

	Sprite lasKsztalt(teksturaLas);
	Sprite wartoscKsztalt(teksturaWartosc);
	Sprite ramkaKsztalt(teksturaRamka);
	Sprite zlodziejKsztalt(teksturaZlodziej);

	

	Vector2f polozenieD(128.0f, 128.0f);
	Vector2f polozenieM(256.0f, 256.0f);

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

	pole.ustawPozycje(polozenieD);
	pole.ustawSprite(lasKsztalt);

	ramka.ustawPozycje(polozenieD);
	ramka.ustawSprite(ramkaKsztalt);

	wartosc.nadajZlodziejowiGrafike(zlodziejKsztalt);
	wartosc.ustawPozycje(polozenieM);
	wartosc.ustawSprite(wartoscKsztalt);
	wartosc.przypiszText(text);

	kompozyt.ustawPole(pole);
	kompozyt.ustawRamke(ramka);
	kompozyt.ustawWartosc(wartosc);
	kompozyt.ustawPozycje(polozenieD);

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
		oknoAplikacji.clear(Color::White);
		kompozyt.rysuj(oknoAplikacji);
		oknoAplikacji.display();
	}
	//system("PAUSE");
	return 0;
}