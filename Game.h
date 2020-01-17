#pragma once
#include "SFML/Graphics.hpp"

class Game
{
public:
	Game(std::string windowTitle, int windowWidth, int windowHeight);
	void updateEvent(sf::RenderWindow& window);
	void renderText(sf::RenderWindow& window, std::string str_text, float x_position, float window_offset_y);
private:
	sf::Text text;
};

