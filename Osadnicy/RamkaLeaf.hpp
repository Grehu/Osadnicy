#pragma once
#include <SFML/Graphics.hpp>
#include "RysunekComponent.hpp"

using namespace std;
using namespace sf;

class RamkaLeaf : public RysunekComponent {
public: 
	void rysuj(RenderWindow & okno);
};