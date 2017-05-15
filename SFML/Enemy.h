#pragma once

class Enemy
{
public:
	Enemy(const int _windowWidth, const int _windowHeight);
	void spawn(float posX, float posY);
	void draw(sf::RenderWindow &window);
	void move(float deltaTime);

private:
	int windowWidth;
	int windowHeight;
	float posX;
	float posY;
	float startingPosX;
	float startingPosY;
	float speedX = 500.0f;
	float speedY = 200.0f;
	bool goRight;
	sf::Sprite enemySprite;
	sf::Texture enemyTexture;
};