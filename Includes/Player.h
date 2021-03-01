#pragma once
#include "SFML/Graphics.hpp"
#include "PlayerControls.h"
#include "Animation.h"
#include "GameObject.h"

class Player : public GameObject
{
public:
    Player(sf::Vector2f position, PlayerControls controls, sf::Texture* texture);
    ~Player();
    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);
    sf::Vector2f GetPosition();
    sf::Vector2f GetSize();
private:
    sf::Vector2f m_velocity;
    PlayerControls m_controls;
    float m_speed;
    Animation m_animation;
};