#pragma once

#include "SFML/Graphics.hpp"

class TextRenderer
{
public:
	TextRenderer(std::string strText, sf::Vector2f position, sf::Color color, int size);
	std::string getString();
	sf::Vector2f getPosition();
	sf::Color getColor();
	int getSize();
	void renderText(sf::RenderWindow &window);
private:
	std::string stringText;
	sf::Vector2f textPosition;
	sf::Color textColor;
	int textSize;
	sf::Text text;
	sf::Font* font;
};

