#include <iostream>
#include <SFML\Graphics.hpp>
#include "Game.h"
#include "Player.h"
#include "Enemy.h"

sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML Application", sf::Style::Fullscreen);

Player player(window.getSize().x, window.getSize().y);
Enemy enemy(window.getSize().x, window.getSize().y);

Game &Game::getInstance()
{
	static Game self;
	return self;
}

// Start of the Game
Game::Game()
{	
	player.spawn(window.getSize().x/2.0f, window.getSize().y - window.getSize().y/4.0f);
	enemy.spawn(window.getSize().x / 2.0f, window.getSize().y - (window.getSize().y / 4.0f) * 3.0f);
}

// Game Loop
void Game::run()
{
	sf::Clock clock;
	while (window.isOpen())
	{
		float deltaTime = clock.restart().asSeconds();
		
		processInput();
		update(deltaTime);
		render();
	}
}

void Game::processInput()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed || 
			sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
		{ window.close(); }

	}
}

void Game::update(float deltaTime)
{
	player.move(deltaTime);
	enemy.move(deltaTime);
}

void Game::render()
{
	window.clear();

	
	player.draw(window);
	enemy.draw(window);
	
	window.display();
}