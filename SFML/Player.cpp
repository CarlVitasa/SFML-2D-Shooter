//#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
 
Player::Player(const int _windowWidth, const int _windowHeight)
{
	windowWidth = _windowWidth;
	windowHeight = _windowHeight;
	playerTexture.loadFromFile("Resources/Sprites/Player.png");
	playerTexture.setSmooth(true);
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

void Player::move(float deltaTime)
{	
	// move left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && 
		playerSprite.getPosition().x >= playerSprite.getTextureRect().width / 2.0f ||
		sf::Joystick::getAxisPosition(0, sf::Joystick::X) == -100 &&
		playerSprite.getPosition().x >= playerSprite.getTextureRect().width / 2.0f)
	{
		playerSprite.move(-speed * deltaTime, 0.0f);
	}

	// move right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && 
		playerSprite.getPosition().x <= windowWidth - playerSprite.getTextureRect().width / 2.0f ||
		sf::Joystick::getAxisPosition(0, sf::Joystick::X) == 100 && 
		playerSprite.getPosition().x <= windowWidth - playerSprite.getTextureRect().width / 2.0f)
	{
		playerSprite.move(speed * deltaTime, 0.0f);
	}
}