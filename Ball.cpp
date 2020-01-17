#include "Ball.h"
#include <cstdlib>
#include <iostream>

Ball::Ball(int ballRadius, sf::Color ballColor, sf::Vector2u windowSize, float windowOffset_y) : circle(sf::CircleShape())
{
	radius = ballRadius;
	color = ballColor;
	window_offset_y = windowOffset_y;
	ball_speed = 120;

	circle.setRadius(radius);
	circle.setFillColor(sf::Color::Green);

	y_direction = 1;

	if (rand() % 1 == 1) {
		x_direction = -1;
	}
	else
	{
		x_direction = 1;
	}
	
	float x_position = (rand() % windowSize.x) / 1.0f;
	float y_position = rand() % windowSize.y + float(windowSize.y/2) + window_offset_y;

	circle.setPosition(x_position, y_position);
}

void Ball::update(sf::RenderWindow& window, sf::Time deltaTime) {
	float speed = deltaTime.asSeconds() * ball_speed;
	
	float move_x = x_direction * speed;
	float move_y = y_direction * speed;

	float ball_x = circle.getPosition().x;
	float ball_y = circle.getPosition().y;
	
	float window_width = (float)window.getSize().x;
	float window_height = (float)window.getSize().y;

	// handle collision with wall
	if (ball_x + move_x <= 0 || ball_x + move_x + radius * 2 >= window_width)
	{
		x_direction *= -1;
	}
	else if (ball_y + move_y <= window_offset_y)
	{
		y_direction *= -1;
	}
	else if (ball_y + move_y + radius * 2 >= window_height)
	{
		std::cout << "lost game" << std::endl;
		y_direction *= -1;
	}

	circle.move(x_direction * speed, y_direction * speed);
}

void Ball::draw(sf::RenderWindow& window) {
	window.draw(circle);
}

int Ball::getRadius() 
{ 
	return radius;
}

sf::Vector2f Ball::getPosition() {
	return circle.getPosition();
}

int Ball::getSpeed() 
{ 
	return ball_speed; 
}

void Ball::changeX_direction() {
	x_direction *= -1;
}

void Ball::changeY_direction() {
	y_direction *= -1;
}