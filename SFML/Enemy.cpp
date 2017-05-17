#include "Enemy.h"

Enemy::Enemy(sf::RenderWindow& l_window) : m_window(l_window)
{
	m_windowWidth = m_window.getSize().x;
	m_windowHeight = m_window.getSize().y;

	m_enemyTexture.loadFromFile("Resources/Sprites/Enemy.png");
	m_enemySprite.setTexture(m_enemyTexture);
	m_enemySprite.setColor(sf::Color(255, 255, 255, 200));
}

void Enemy::spawn(float l_posX, float l_posY)
{
	m_startingPosX = l_posX;
	m_startingPosY = l_posY;
	m_enemySprite.setPosition(l_posX, l_posY);
	m_enemySprite.setOrigin(m_enemySprite.getTextureRect().width / 2.0f,
							m_enemySprite.getTextureRect().height / 2.0f);
}

void Enemy::draw(sf::RenderWindow& window)
{
	window.draw(m_enemySprite);
}

void Enemy::move(float l_deltaTime)
{
	m_posX = m_speedX * l_deltaTime;
	m_posY = m_speedY * l_deltaTime;

	m_enemySprite.move({ m_posX, m_posY});
	
	if (m_enemySprite.getPosition().x >= m_startingPosX + m_enemySprite.getTextureRect().width * 2.0f ||
		m_enemySprite.getPosition().x <= m_startingPosX + m_enemySprite.getTextureRect().width * -2.0f)
	{ m_speedX *= -1; }
}