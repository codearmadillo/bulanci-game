#pragma once
#include "SFML/Graphics.hpp"

class Animation
{
public:
    Animation(sf::Texture* texture, sf::RectangleShape* body, sf::Vector2i rectSize, int framesPerSecond, bool autorun);
    void Update(float deltaTime);
    void SetAnimation(int animation_row, bool flip);
    void Stop();
    void Start();
    bool IsRunning();
private:
    sf::Texture* p_texture;
    sf::RectangleShape* p_body;
    sf::Vector2i m_rectSize;
    sf::Vector2i m_rectPosition;
    int m_imageRows;
    int m_imageCols;
    int m_framesPerSecond;
    bool m_running;
    bool m_isFlipped;
    float m_elapsedDelta;
};