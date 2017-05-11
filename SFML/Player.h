#pragma once

class Player
{
public:
	Player(int _windowWidth, int _windowHeight);
	void spawn(int posX, int posY);
	void draw(sf::RenderWindow &window);
	void move(double deltaTime);

private:
	int windowWidth;
	int windowHeight;
	float speed = 500.0f; // when changing speed rebuild solution before compiling
	sf::Sprite playerSprite;
	sf::Texture playerTexture;
};