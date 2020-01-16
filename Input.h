#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"

struct Keys {
    int L, R, U, D = 0;
};

class Input
{
public:
	Keys getKeyPressed();
	sf::Vector2i mousePosition();
	int mouseClick();
};

