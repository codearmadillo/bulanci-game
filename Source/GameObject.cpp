#include "SFML/Graphics.hpp"
#include "../Includes/GameObject.h"

GameObject::GameObject(sf::Vector2f size, sf::Vector2f position, sf::Texture* texture) {
    /** Set body */
    this->m_body.setSize(size);
    this->m_body.setPosition(position);
    this->m_body.setOrigin(size / 2.0f);
    if(texture == nullptr) {
        this->m_body.setFillColor(sf::Color(255, 0, 0));
    } else {
        this->m_body.setTexture(texture);
    }
}
GameObject::~GameObject() = default;
void GameObject::SetStaticTexture(sf::IntRect intRect) {
    this->m_body.setTextureRect({intRect.left * intRect.width, intRect.top * intRect.height, intRect.width, intRect.height});
}
void GameObject::SetAnimatedTexture() {
    throw std::runtime_error("No implemented");
}