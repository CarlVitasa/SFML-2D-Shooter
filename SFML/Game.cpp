#include "Game.h"
#include "Projectile.h"

const int m_windowWidth = 700;
const int m_windowHeight = 900;
std::string m_playerDirection = "None";

sf::RenderWindow m_window(sf::VideoMode(m_windowWidth, m_windowHeight), "SFML-2D-Shooter", sf::Style::Default);

Player player(m_window);
Enemy enemy(m_window);
Projectile projectile(m_window);

Game& Game::getInstance()
{
	static Game self;
	return self;
}

// Start of the Game
Game::Game()
{	
	player.spawn(m_windowWidth /2.0f, m_windowHeight - m_windowHeight /6.0f);
	enemy.spawn(m_windowWidth / 2.0f, m_windowHeight - (m_windowHeight / 4.0f) * 3.0f);
}

// Game Loop
void Game::runGameLoop()
{
	sf::Clock clock;
	while (m_window.isOpen())
	{
		float deltaTime = clock.restart().asSeconds();
		
		processInput();	
		update(deltaTime);
		render();
	}
}

void Game::processInput()
{
	// X Button --> quit game
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{ m_window.close(); }
	}

	// escape key --> quit game
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{ m_window.close(); }
	
	// move player Left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) &&
		player.getPosX() >= player.getWidth() / 2.0f ||
		sf::Joystick::getAxisPosition(0, sf::Joystick::X) == -100 &&
		player.getPosX() >= player.getWidth() / 2.0f)
	{
		m_playerDirection = "Left";
	}

	// move player right
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) &&
		player.getPosX() <= m_windowWidth - player.getWidth() / 2.0f ||
		sf::Joystick::getAxisPosition(0, sf::Joystick::X) == 100 &&
		player.getPosX() <= m_windowWidth - player.getWidth() / 2.0f)
	{
		m_playerDirection = "Right";
	}
	else { m_playerDirection = "None"; }
}

void Game::update(float l_deltaTime)
{
	player.move(m_playerDirection, l_deltaTime);
	enemy.move(l_deltaTime);
}

void Game::render()
{
	m_window.clear();

	player.draw(m_window);
	enemy.draw(m_window);
	
	m_window.display();
}