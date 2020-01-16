#include "Input.h"

Keys Input::getKeyPressed() {
    Keys keys;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        keys.U = 1;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        keys.L = 1;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        keys.D = 1;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        keys.R = 1;
    }

    return keys;
}

sf::Vector2i Input::mousePosition() {
    // get global mouse position
    sf::Vector2i position = sf::Mouse::getPosition();
    
    std::cout << position.x << " " << position.y << std::endl;

    return position;
}

int Input::mouseClick() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        return 1;
    }
    else if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        return 2;
    }
    else {
        return 0;
    }
}