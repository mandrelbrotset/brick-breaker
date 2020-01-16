#pragma once

#include "SFML/Graphics.hpp"

class Ball
{
public:
	Ball(int ballRadius, sf::Color ballColor, sf::Vector2u windowSize);
	void update(sf::RenderWindow& window, sf::Time delta_time);
	void draw(sf::RenderWindow& window);
	int getRadius();
	sf::Vector2f getPosition();
	int getSpeed();
	void changeX_direction();
	void changeY_direction();

private:
	sf::CircleShape circle;
	sf::Color color;
	int radius;
	int ball_speed;
	int x_direction;
	int y_direction;
};

