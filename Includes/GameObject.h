#pragma once
#include "SFML/Graphics.hpp"

class GameObject
{
public:
    GameObject(sf::Vector2f size, sf::Vector2f position, sf::Texture* texture);
    ~GameObject();
    virtual void Update(float deltaTime) = 0;
    virtual void Draw(sf::RenderWindow& window) = 0;
    void SetStaticTexture(sf::IntRect intRect);
    void SetAnimatedTexture();
protected:
    sf::RectangleShape m_body;
};