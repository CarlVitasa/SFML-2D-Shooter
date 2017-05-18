#include "Projectile.h"

Projectile::Projectile(sf::RenderWindow& l_window) : m_window(l_window)
{
	m_projectileTexture.loadFromFile("Resources/Sprites/Projectile.png");
	m_projectileSprite.setTexture(m_projectileTexture);
	m_projectileSprite.setColor(sf::Color(255, 255, 255, 200));
}

void Projectile::spawn(float l_posX, float l_posY)
{
	m_projectileSprite.setPosition(l_posX, l_posY);
	m_projectileSprite.setOrigin(m_projectileSprite.getTextureRect().width / 2.0f,
								 m_projectileSprite.getTextureRect().height / 2.0f);
}

void Projectile::shoot(float l_deltaTime)
{
	m_projectileSprite.move({ 0, -m_speed * l_deltaTime });
}

void Projectile::draw(sf::RenderWindow & l_window)
{
	m_projectileTexture.loadFromFile("Resources/Sprites/Projectile.png");
	m_projectileSprite.setTexture(m_projectileTexture);
	m_projectileTexture.setSmooth(true);
	l_window.draw(m_projectileSprite);
}

float Projectile::getPosY()
{
	return m_projectileSprite.getPosition().y;
}
