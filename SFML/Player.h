#pragma once

class Player
{
public:
	Player(const int _windowWidth, const int _windowHeight);
	void spawn(float posX, float posY);
	void draw(sf::RenderWindow &window);
	void move(float deltaTime);

private:
	int windowWidth;
	int windowHeight;
	const float speed = 1000.0f; // when changing speed rebuild solution before compiling
	sf::Sprite playerSprite;
	sf::Texture playerTexture;
};