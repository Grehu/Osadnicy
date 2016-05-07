#pragma once
#include <SFML\Graphics.hpp>
#include "RysunekComponent.hpp"

using namespace sf;

class PoleLeaf : public RysunekComponent {

public:
	void ustawOrientacje(int orientacja);
};