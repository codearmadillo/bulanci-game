#pragma once

#include "SFML/Graphics.hpp"
#include "GameObject.h"

class StaticObject : public GameObject
{
public:
    StaticObject(sf::Vector2f size, sf::Vector2f position, sf::Texture* texture);
    ~StaticObject();
    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);
    virtual sf::FloatRect GetCollisionBox();
};