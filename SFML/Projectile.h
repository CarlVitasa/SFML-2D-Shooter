#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Projectile
{
public:
	Projectile(sf::RenderWindow& l_window);
	void spawn(float l_posX, float l_posY);
	void shoot(float l_deltaTime);
	void draw(sf::RenderWindow& l_window);
	float getPosY();
private:
	sf::RenderWindow& m_window;
	int m_windowWidth;
	int m_windowHeight;
	float m_posX;
	float m_posY;
	const float m_speed = 1000.0f;
	sf::Sprite m_projectileSprite;
	sf::Texture m_projectileTexture;
};