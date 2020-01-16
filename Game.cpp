#include "Game.h"
#include "Input.h"
#include "TextRenderer.h"
#include "Paddle.h"
#include "Ball.h"
#include "Block.h"
#include "Physics.h"

#include <unordered_map>
#include <cstdlib>

int BLOCKS_PER_ROW = 20;
int NUM_OF_ROWS = 5;
int NUM_OF_BLOCKS = 40;

Game::Game(std::string windowTitle, int windowWidth, int windowHeight) 
{
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), windowTitle);
    window.setFramerateLimit(60);

    // TextRenderer text1("Hello", sf::Vector2f(200.0, 200.0), sf::Color::Red, 30);
    
    // Map to store all blocks using x, y coords(BlockKey) as the key
    std::unordered_map<BlockKey, Block, KeyHasher> blockMap;
    std::unordered_map <BlockKey, Block, KeyHasher>::iterator b_it;
 
    float blockSide = window.getSize().x / BLOCKS_PER_ROW;

    Ball ball(int(blockSide / 4), sf::Color::White, window.getSize());

    Paddle paddle(int(blockSide), int(blockSide * 4), sf::Color::White, window.getSize());
    
    std::pair<std::unordered_map<BlockKey, Block>::iterator, bool> ret;

    Physics gamePhysics;

    srand(time(NULL));

    // generate random positions for blocks
    for (int i = 0; i < NUM_OF_BLOCKS; i++)
    {
        BlockKey key;
        key.x = (rand() % BLOCKS_PER_ROW) * blockSide;
        key.y = (rand() % NUM_OF_ROWS) * blockSide;

        Block tempBlock = Block(key.x, key.y, blockSide);

        ret = blockMap.insert(std::pair<BlockKey, Block>(key, tempBlock));
        // if block wasn't added increase number of blocks to generate
        if (ret.second == false) 
        {
            NUM_OF_BLOCKS += 1;
        }
    }
    
    sf::Clock clock;

    // Game loop
    while (window.isOpen())
    {
        updateEvent(window);
        window.clear();

        sf::Time deltaTime = clock.restart();

        // draw stuff
        gamePhysics.update(window, deltaTime, ball, paddle);

        ball.update(window, deltaTime);
        paddle.update(window, deltaTime);

        ball.draw(window);
        paddle.draw(window);
        

        // Show(draw) the blocks
        for (b_it = blockMap.begin(); b_it != blockMap.end();  ++b_it) 
        {
            b_it->second.draw(window);

            float block_x = b_it->second.getXposition();
            float block_y = b_it->second.getYposition();
            float block_side = b_it->second.getSide();

            float ball_x = ball.getPosition().x;
            float ball_y = ball.getPosition().y;
            float ball_radius = ball.getRadius();

            // collision under the block
            if (int(ball_x + ball_radius) >= int(block_x) &&
                int(ball_x) <= int(block_x + block_side))
            {
                if (int(ball_y) == int(block_y + block_side)) 
                {
                    ball.changeY_direction();
                }
                else if (int(block_y + block_side) >= int(ball_y) &&
                    int(block_y + block_side) <= int(ball_y + ball_radius/2))
                {
                    ball.changeY_direction();
                }
            }

            // collision on top the block
            if (int(ball_x + ball_radius) >= int(block_x) &&
                int(ball_x) <= int(block_x + block_side))
            {
                if (int(ball_y + ball_radius * 2) == int(block_y))
                {
                    ball.changeY_direction();
                    std::cout << "yay top" << std::endl;
                }
                else if (int(block_y) >= int(ball_y + ball_radius * 2) &&
                        int(block_y) <= int(ball_y + ball_radius))
                {
                    ball.changeY_direction();
                    std::cout << "uh top" << std::endl;
                }
            }

            // collision to left of the block
            if (int(ball_y + ball_radius) >= int(block_y) &&
                int(ball_y) <= int(block_y + block_side))
            {
                if (int(ball_x + ball_radius * 2) == int(block_x))
                {
                    ball.changeX_direction();
                }
                else if (int(block_x) >= int(ball_x + ball_radius) && 
                        int(block_x) <= int(ball_x + ball_radius * 2))
                {
                    ball.changeX_direction();
                }
            }

            // collision to right of the block
            if (int(ball_y + ball_radius) >= int(block_y) &&
                int(ball_y) <= int(block_y + block_side))
            {
                if (int(ball_x) == int(block_x + block_side))
                {
                    std::cout << "block right" << std::endl;
                    ball.changeX_direction();
                }
                else if (int(block_x + block_side) >= int(ball_x) && 
                        int(block_x + block_side) <= int(ball_x + ball_radius/2))
                {
                    std::cout << "uh uh right" << std::endl;
                    ball.changeX_direction();
                }
            }
            
        }

        // End drawing

        // Present window after drawing items
        window.display();
    }
}

void Game::updateEvent(sf::RenderWindow& window) {
    // Poll window for events
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}