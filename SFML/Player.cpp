#include "Player.h"
#include "Projectile.h"

Player::Player(sf::RenderWindow& l_window) : m_window(l_window)
{
	m_windowWidth = m_window.getSize().x;
	m_windowHeight = m_window.getSize().y;
	m_playerTexture.loadFromFile("Resources/Sprites/Player.png");
	m_playerTexture.setSmooth(true);
	m_playerSprite.setTexture(m_playerTexture);
}

void Player::spawn(float l_posX, float l_posY)
{
	m_playerSprite.setPosition(l_posX, l_posY);
	m_playerSprite.setOrigin(m_playerSprite.getTextureRect().width / 2.0f,
							 m_playerSprite.getTextureRect().height / 2.0f);
}

void Player::draw(sf::RenderWindow& l_window)
{
	l_window.draw(m_playerSprite);
}

float Player::getPosX()
{
	return m_playerSprite.getPosition().x;
}

float Player::getPosY()
{
	return m_playerSprite.getPosition().y;
}

int Player::getWidth()
{
	return m_playerSprite.getTextureRect().width;
}

int Player::getHeight()
{
	return m_playerSprite.getTextureRect().height;
}

void Player::move(std::string l_playerDirection, float l_deltaTime)
{	
	m_deltaTime = l_deltaTime;
	
	// move left
    if (l_playerDirection == "Left")
	{
		m_playerSprite.move(-m_speed * l_deltaTime, 0.0f);
	}

	// move right
	else if (l_playerDirection == "Right")
	{
		m_playerSprite.move(m_speed * l_deltaTime, 0.0f);
	}
	else if (l_playerDirection == "None")
	{
		m_playerSprite.move(0.0f, 0.0f);
	}
}