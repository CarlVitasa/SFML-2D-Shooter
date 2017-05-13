//#include <iostream>
#include <SFML\Graphics.hpp>
#include "Player.h"
 
Player::Player(int _windowWidth, int _windowHeight)
{
	windowWidth = _windowWidth;
	windowHeight = _windowHeight;
	playerTexture.loadFromFile("Sprites/Player.png");
	playerSprite.setTexture(playerTexture);
	playerSprite.setColor(sf::Color(255, 255, 255, 200));
}

void Player::spawn(float posX, float posY)
{
	playerSprite.setPosition(posX, posY);
	playerSprite.setOrigin(playerSprite.getTextureRect().width / 2.0f,
	playerSprite.getTextureRect().height / 2.0f);
}

void Player::draw(sf::RenderWindow &window)
{
	window.draw(playerSprite);
}

void Player::move(double deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && 
		playerSprite.getPosition().x >= playerSprite.getTextureRect().width / 2.0f ||
		sf::Joystick::getAxisPosition(0, sf::Joystick::X) == -100 &&
		playerSprite.getPosition().x >= playerSprite.getTextureRect().width / 2.0f)
	{
		playerSprite.move(-speed * deltaTime, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && 
		playerSprite.getPosition().x <= windowWidth - playerSprite.getTextureRect().width / 2.0f ||
		sf::Joystick::getAxisPosition(0, sf::Joystick::X) == 100 && 
		playerSprite.getPosition().x <= windowWidth - playerSprite.getTextureRect().width / 2.0f)
	{
		playerSprite.move(speed * deltaTime, 0);
	}
}