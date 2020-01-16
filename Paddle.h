#pragma once

#include "SFML/Graphics.hpp"
#include "Input.h"

class Paddle
{
public:
	Paddle(int height, int width, sf::Color color, sf::Vector2u);
	void update(sf::RenderWindow& window, sf::Time delta_time);
	void draw(sf::RenderWindow& window);
	sf::Vector2f getPosition();
	int getSpeed();
	int getWidth();
	int getHeight();
	
private:
	sf::RectangleShape rect;
	sf::Color color;	
	int height;
	int width;
	int paddle_speed;
	int pos_x;
};

