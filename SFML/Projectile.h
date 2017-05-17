#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Projectile
{
public:
	Projectile(sf::RenderWindow& l_window);
	void spawn(float l_posX, float l_posY, float l_deltaTime);

private:
	sf::RenderWindow& m_window;
	int m_windowWidth;
	int m_windowHeight;
	float m_posX;
	float m_posY;
	const float m_speed = 200.0f;
	sf::Sprite m_projectileSprite;
	sf::Texture m_projectileTexture;
};