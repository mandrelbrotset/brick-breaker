#pragma once

#include <SFML/Graphics.hpp>

struct BlockKey {
    float x;
    float y;

    bool operator==(const BlockKey& other) const {
        return (x == other.x
            && y == other.y);
    }
};

struct KeyHasher {
    std::size_t operator()(const BlockKey& k) const
    {
        using std::size_t;
        using std::hash;
        using std::string;

        return ((hash<float>()(k.x)
            ^ (hash<float>()(k.y) << 1)) >> 1);
    }
};

class Block
{
public:
	Block(float positionX, float positionY, float blockSide);
	void draw(sf::RenderWindow& window);
    float getSide();
    float getXposition();
    float getYposition();
private:
	sf::RectangleShape rect;
	sf::Color color;
	float side;
	float positionX;
	float positionY;
};

