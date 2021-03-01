#include "SFML/Graphics.hpp"
#include "../Includes/Animation.h"
#include <math.h>

Animation::Animation(sf::Texture* texture, sf::RectangleShape* body, sf::Vector2i rectSize, int framesPerSecond, bool autorun)
{
    this->p_texture = texture;
    this->p_body = body;
    /** Get rectangle size for one image */
    this->m_rectSize = rectSize;
    /** Get rows and cols in image */
    this->m_imageRows = texture->getSize().y / rectSize.y;
    this->m_imageCols = texture->getSize().x / rectSize.x;
    /** Save frames per second */
    this->m_framesPerSecond = framesPerSecond;
    /** Set default image */
    this->m_rectPosition = {0, 0};
    this->m_elapsedDelta = 0.0f;
    this->m_running = autorun;
    this->m_isFlipped = false;
}
void Animation::Update(float deltaTime)
{
    if(this->m_running) {
        this->m_elapsedDelta += deltaTime;
        if(this->m_elapsedDelta >= 1.0f / this->m_framesPerSecond) {
            this->m_elapsedDelta -= 1.0f / this->m_framesPerSecond;
            this->m_rectPosition.x++;
            if(this->m_rectPosition.x > this->m_imageCols - 1)
                this->m_rectPosition.x = 0;
        }
    }
    /** Update rectangle */
    this->p_body->setTextureRect({
    this->m_rectPosition.x * this->m_rectSize.x + (this->m_isFlipped ? this->m_rectSize.x : 0),
    this->m_rectPosition.y * this->m_rectSize.y,
         this->m_rectSize.x * (this->m_isFlipped ? -1 : 1),
         this->m_rectSize.y
    });
}
void Animation::SetAnimation(int animation_row, bool flip)
{
    if(animation_row == this->m_rectPosition.y && flip == this->m_isFlipped)
        return;
    if(animation_row > this->m_imageRows)
        throw std::runtime_error("Invalid animation - Animation is out of scope");
    this->m_rectPosition.x = 0;
    this->m_rectPosition.y = animation_row;
    this->m_isFlipped = flip;
}
bool Animation::IsRunning() { return this->m_running; }
void Animation::Stop() {
    this->m_running = false;
    this->m_rectPosition.x = 0;
    this->m_elapsedDelta = 0.0f;
}
void Animation::Start() {
    this->m_running = true;
}
