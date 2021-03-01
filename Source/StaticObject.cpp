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

sf::FloatRect StaticObject::GetCollisionBox() {
    sf::Vector2f position = this->m_body.getPosition();
    sf::Vector2f size = this->m_body.getSize();
    return sf::FloatRect {
        position.x, position.y,
        position.x + size.x, position.y + size.y
    };
}
