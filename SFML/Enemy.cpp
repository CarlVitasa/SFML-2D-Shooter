//#include <iostream>
#include <SFML\Graphics.hpp>
#include "Enemy.h"

Enemy::Enemy(int _windowWidth, int _windowHeight)
{
	windowWidth = _windowWidth;
	windowHeight = _windowHeight;

	enemyTexture.loadFromFile("Sprites/Enemy.png");
	enemySprite.setTexture(enemyTexture);
	enemySprite.setColor(sf::Color(255, 255, 255, 200));
	enemySprite.setPosition(512, 100);
	enemySprite.setOrigin(enemySprite.getTextureRect().width / 2.0f,
						  enemySprite.getTextureRect().height / 2.0f);
}

void Enemy::draw(sf::RenderWindow &window)
{
	window.draw(enemySprite);
}

void Enemy::move(double deltaTime)
{
	posX = speed * deltaTime;
	enemySprite.move(sf::Vector2f(posX, posY));
	if (enemySprite.getPosition().x >= windowWidth - enemySprite.getTextureRect().width / 2.0f || 
		enemySprite.getPosition().x <= enemySprite.getTextureRect().width / 2.0f)
	{ speed *= -1; }
}

