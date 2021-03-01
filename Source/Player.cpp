#include "../Includes/Player.h"
#include "../Includes/GameObject.h"
#include "SFML/Graphics.hpp"

Player::Player(sf::Vector2f position, PlayerControls controls, sf::Texture* texture)
    : GameObject(sf::Vector2f(64.0f, 64.0f), position, texture),
    m_animation(texture, &m_body, { 64, 64 }, 10, false)
{
    this->m_speed = 100.0f;
    this->m_controls = controls;
}
Player::~Player() = default;
void Player::Update(float deltaTime)
{
    /** Movement */
    this->m_velocity *= 0.5f;
    if(sf::Keyboard::isKeyPressed(this->m_controls.Left))
        this->m_velocity.x -= this->m_speed;
    if(sf::Keyboard::isKeyPressed(this->m_controls.Right))
        this->m_velocity.x += this->m_speed;
    if(sf::Keyboard::isKeyPressed(this->m_controls.Up))
        this->m_velocity.y -= this->m_speed;
    if(sf::Keyboard::isKeyPressed(this->m_controls.Down))
        this->m_velocity.y += this->m_speed;
    /** Update animation */
    if(this->m_velocity.x == 0.0f && this->m_velocity.y == 0.0f) {
        if(this->m_animation.IsRunning())
            this->m_animation.Stop();
    } else {
        if(!this->m_animation.IsRunning())
            this->m_animation.Start();
    }
    this->m_animation.Update(deltaTime);
    /** Move */
    this->m_body.move(this->m_velocity * deltaTime);
}
void Player::Draw(sf::RenderWindow& window)
{
    window.draw(this->m_body);
}
sf::Vector2f Player::GetPosition() {
    return this->m_body.getPosition();
}
sf::Vector2f Player::GetSize() {
    return this->m_body.getSize();
}
