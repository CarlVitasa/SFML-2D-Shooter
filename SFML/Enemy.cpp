#include <iostream>
#include <SFML/Graphics.hpp>
#include "Enemy.h"

Enemy::Enemy(const int _windowWidth, const int _windowHeight)
{
	windowWidth = _windowWidth;
	windowHeight = _windowHeight;

	enemyTexture.loadFromFile("Resources/Sprites/Enemy.png");
	enemySprite.setTexture(enemyTexture);
	enemySprite.setColor(sf::Color(255, 255, 255, 200));
}

void Enemy::spawn(float posX, float posY)
{
	startingPosX = posX;
	startingPosY = posY;
	enemySprite.setPosition(posX, posY);
	enemySprite.setOrigin(enemySprite.getTextureRect().width / 2.0f,
						  enemySprite.getTextureRect().height / 2.0f);
}

void Enemy::draw(sf::RenderWindow &window)
{
	window.draw(enemySprite);
}

void Enemy::move(float deltaTime)
{
	posX = speedX * deltaTime;
	posY = speedY * deltaTime;

	enemySprite.move({posX, posY});
	
	if (enemySprite.getPosition().x >= startingPosX + enemySprite.getTextureRect().width * 2.0f ||
		enemySprite.getPosition().x <= startingPosX + enemySprite.getTextureRect().width * -2.0f)
	{ speedX *= -1; }
}