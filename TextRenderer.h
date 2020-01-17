#pragma once

#include "SFML/Graphics.hpp"

class TextRenderer
{
public:
	TextRenderer(std::string strText, sf::Vector2f position, sf::Color color, int size);
	void renderText(sf::RenderWindow &window);
private:
	std::string str_text;
	sf::Vector2f position;
	sf::Color color;
	int size;
	sf::Text text;
};

