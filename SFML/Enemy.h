#pragma once

class Enemy
{
public:
	Enemy(int _windowWidth, int _windowHeight);
	void draw(sf::RenderWindow &window);
	void move(double deltaTime);

private:
	int windowWidth;
	int windowHeight;
	float posX;
	float posY;
	float speed = 500.0f;
	bool goRight;
	sf::Sprite enemySprite;
	sf::Texture enemyTexture;
};