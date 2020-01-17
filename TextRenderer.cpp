#include "TextRenderer.h"

#include <iostream>
#include <SFML/Graphics/Text.hpp>

TextRenderer::TextRenderer(std::string strText, sf::Vector2f textPosition, sf::Color textColor, int textSize)
{
	str_text = strText;
	position = textPosition;
	color = textColor;
	size = textSize;

	sf::Font font;

	text.setString(str_text);
	text.setPosition(position);
	text.setFillColor(color);
	text.setCharacterSize(size);
}

void TextRenderer::renderText(sf::RenderWindow &window) {
	


	window.draw(text);
}