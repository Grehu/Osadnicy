#include "RamkaLeaf.hpp"
#include <iostream>

void RamkaLeaf::rysuj(RenderWindow & okno)
{
	std::cout << "Uruchomiono rysowanie ramki." << std::endl;
	sprite.setPosition(*pozycja);
	okno.draw(sprite);
}
