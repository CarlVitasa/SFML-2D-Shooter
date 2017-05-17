#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Enemy
{
public:
	Enemy(sf::RenderWindow& l_window);
	void spawn(float l_posX, float l_posY);
	void draw(sf::RenderWindow &window);
	void move(float deltaTime);

private:
	sf::RenderWindow& m_window;
	int m_windowWidth;
	int m_windowHeight;
	float m_posX;
	float m_posY;
	float m_startingPosX;
	float m_startingPosY;
	float m_speedX = 500.0f;
	float m_speedY = 200.0f;
	bool m_goRight;
	sf::Sprite m_enemySprite;
	sf::Texture m_enemyTexture;
};