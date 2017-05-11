#include <iostream>
#include <SFML\Graphics.hpp>
#include "Game.h"
#include "Player.h"
#include "Enemy.h"

sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML Application", sf::Style::Fullscreen);

Player player(window.getSize().x, window.getSize().y);
Enemy enemy(window.getSize().x, window.getSize().y);

Game::Game()
{	
	window.setFramerateLimit(500);
	player.spawn(window.getSize().x/2, window.getSize().y - window.getSize().y/4);
}

void Game::Run()
{
	sf::Clock clock;
	while (window.isOpen())
	{
		double deltaTime = clock.restart().asSeconds();
		
		ProcessInput();
		Update(deltaTime);
		Render();
	}
}

void Game::ProcessInput()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed || 
			sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
		{ window.close(); }

	}
}

void Game::Update(double deltaTime) 
{
	player.move(deltaTime);
	enemy.move(deltaTime);
}

void Game::Render()
{
	window.clear();
	player.draw(window);
	enemy.draw(window);
	window.display();
}