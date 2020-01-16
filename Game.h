#pragma once
#include "SFML/Graphics.hpp"

class Game
{
public:
	Game(std::string windowTitle, int windowWidth, int windowHeight);
	void updateEvent(sf::RenderWindow& window);
};

