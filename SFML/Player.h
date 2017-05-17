#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
class Player
{
public:
	Player(sf::RenderWindow& l_window);
	void spawn(float l_posX, float l_posY);
	void draw(sf::RenderWindow& l_window);
	float getPosX();
	float getPosY();
	float getWidth();
	float getHeight();
	void move(std::string l_playerDirection, float l_deltaTime);

private:
	sf::RenderWindow& m_window;
	int m_windowWidth;
	int m_windowHeight;
	float m_posX;
	float m_posY;
	float m_deltaTime;
	const float m_speed = 1000.0f; // when changing speed rebuild solution before compiling
	sf::Sprite m_playerSprite;
	sf::Texture m_playerTexture;
};