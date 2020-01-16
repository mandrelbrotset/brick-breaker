#include "Physics.h"
#include "Input.h"
#include "SFML/Graphics.hpp"

// Physics::Physics(Ball* ball, Paddle* paddle, std::unordered_map<BlockKey, Block, std::hash<KeyHasher>>* blockMap) :
Physics::Physics()
{

}

void Physics::update(sf::RenderWindow &window, sf::Time elapsedTime, Ball& ball, Paddle& paddle)
{
	float window_width = (float)window.getSize().x;
	float window_height = (float)window.getSize().y;

	float ball_x = ball.getPosition().x;
	float ball_y = ball.getPosition().y;
	float ball_radius = ball.getRadius();

	float paddle_x = paddle.getPosition().x;
	float paddle_y = paddle.getPosition().y;
	float paddle_width = (float)paddle.getWidth();
	float paddle_height = (float)paddle.getHeight();

	if(ball_x + ball_radius >= paddle_x &&
		ball_x + ball_radius <= paddle_x + paddle_width)
	{
		if (int(ball_y + ball_radius * 2) >= int(paddle_y))
		{
			ball.changeY_direction();
		}
		else if (paddle_y <= ball_y + ball_radius * 2 && paddle_y >= ball_y + ball_radius)
		{
			ball.changeY_direction();
			std::cout << "estimation happened here" << std::endl;
		}
	}

}
