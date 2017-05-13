#pragma once

class Player
{
public:
	Player(int _windowWidth, int _windowHeight);
	void spawn(float posX, float posY);
	void draw(sf::RenderWindow &window);
	void move(double deltaTime);

private:
	int windowWidth;
	int windowHeight;
	double speed = 500; // when changing speed rebuild solution before compiling
	sf::Sprite playerSprite;
	sf::Texture playerTexture;
};