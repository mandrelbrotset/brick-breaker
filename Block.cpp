#include "Block.h"

#include <cstdlib>

	Block::Block(float x, float y, float blockSide) :
	positionX(x),
	positionY(y),
	side(blockSide),
	rect(sf::RectangleShape())
{
	sf::Color colors[5] = {
		sf::Color::White,
		sf::Color(255, 55, 0),
		sf::Color(0, 255, 195),
		sf::Color(255, 55, 0),
		sf::Color(220, 0, 255)
	};

	int index = rand() % 5;

	color = colors[index];

	rect.setOutlineColor(sf::Color::Black);
	rect.setOutlineThickness(1.0);
	rect.setFillColor(color);
	rect.setSize(sf::Vector2f(side, side));
	rect.setPosition(positionX, positionY);
}
void Block::draw(sf::RenderWindow& window) {
	window.draw(rect);
}

float Block::getSide() {
	return side;
}

float Block::getXposition() {
	return positionX;
}

float Block::getYposition() {
	return positionY;
}