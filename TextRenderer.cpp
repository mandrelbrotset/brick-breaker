#include "TextRenderer.h"

#include <iostream>

TextRenderer::TextRenderer(std::string strText, sf::Vector2f position, sf::Color color, int size) : text(sf::Text()), font(new sf::Font()){
	/*
	text = new sf::Text();
	sf::Font font;
	
	text->setFont(font);
	text->setCharacterSize(size);
	text->setFillColor(color);
	*/

	if (!font->loadFromFile("Calibri.ttf")) {
		std::cout << "error" << std::endl;
	} 
	else {
		std::cout << "success" << std::endl;
	}
	
	stringText = strText;
	textPosition = position;
	textColor = color;
	textSize = size;
}

std::string TextRenderer::getString() {
	return stringText;
}

sf::Vector2f TextRenderer::getPosition() {
	return textPosition;
}

sf::Color TextRenderer::getColor() {
	return textColor;
}

int TextRenderer::getSize() {
	return textSize;
}

void TextRenderer::renderText(sf::RenderWindow &window) {
	
	sf::Text t1;
	
	t1.setString("testing");
	t1.setFont(*font);
	t1.setCharacterSize(20);
	t1.setFillColor(sf::Color::Red);
	t1.setPosition(sf::Vector2f(20, 300));
	

	window.draw(text);
}