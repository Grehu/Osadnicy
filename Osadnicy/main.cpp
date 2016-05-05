#include <iostream>
#include <cmath>
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Window.hpp>
//#include <cstring>
//#include <map>

using namespace sf;
//using namespace std;


int width = 800;
int height = 600;
int main() {
	RenderWindow oknoAplikacji(VideoMode(width, height, 32), "Osadnicy z Catanu");

	while (oknoAplikacji.isOpen())
	{
		oknoAplikacji.clear();
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
		oknoAplikacji.display();
	}
	//system("PAUSE");
	return 0;
}