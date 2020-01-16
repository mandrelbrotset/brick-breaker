#include "Paddle.h"

Paddle::Paddle(int paddleHeight, int paddleWidth, sf::Color paddleColor, sf::Vector2u windowSize) 
	: rect(sf::RectangleShape()) 
{
	height = paddleHeight;
	width = paddleWidth;
	color = paddleColor;

	pos_x = 0;

	paddle_speed = 400;

	rect.setSize(sf::Vector2f(paddleWidth, paddleHeight));
	rect.setPosition(sf::Vector2f(windowSize.x - width, windowSize.y - height));
}

void Paddle::update(sf::RenderWindow& window, sf::Time deltaTime)
{
	int window_width = window.getSize().x;
	int window_height = window.getSize().y;

	float speed = deltaTime.asSeconds() * paddle_speed;

	Input input;
	Keys k = input.getKeyPressed();
	int paddlePosX = rect.getPosition().x;
	
	if (k.L == 1 && paddlePosX >= 0) 
	{
		rect.move((-1) * speed, 0.0);
	}
	else if (k.R == 1 && paddlePosX + width < window_width)
	{
		rect.move(speed, 0.0);
	}
}

void Paddle::draw(sf::RenderWindow& window) 
{
	window.draw(rect);
}

sf::Vector2f Paddle::getPosition() 
{
	return rect.getPosition();
}

int Paddle::getSpeed() 
{ 
	return paddle_speed; 
}

int Paddle::getWidth() 
{ 
	return width; 
}

int Paddle::getHeight() 
{ 
	return height; 
}