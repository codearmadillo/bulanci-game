#include "../Includes/StaticObject.h"
#include "../Includes/GameObject.h"
#include "SFML/Graphics.hpp"

StaticObject::StaticObject(sf::Vector2f size, sf::Vector2f position, sf::Texture* texture) : GameObject(size, position, texture) {
    this->SetStaticTexture({1, 0, 64, 64});
}
StaticObject::~StaticObject() = default;
void StaticObject::Update(float deltaTime)
{

}
void StaticObject::Draw(sf::RenderWindow& window)
{
    window.draw(this->m_body);
}