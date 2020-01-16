#pragma once

#include "Ball.h"
#include "Paddle.h"
#include "Block.h"
#include <unordered_map>

class Physics
{
public:
	// Physics(Ball* ball, Paddle* paddle, std::unordered_map<BlockKey, Block, KeyHasher>* map);
	Physics();
	void update(sf::RenderWindow& window, sf::Time elapsedTime, Ball& ball, Paddle& paddle);
private:
	// std::unordered_map<BlockKey, Block, std::hash<KeyHasher>>* map;
};

