#include "Game.h"
#include "Projectile.h"

const int m_windowWidth = 700;
const int m_windowHeight = 900;
std::string m_playerDirection = "None";
bool isFiring = false;
bool popBack = false;

sf::RenderWindow m_window(sf::VideoMode(m_windowWidth, m_windowHeight), "SFML-2D-Shooter", sf::Style::Default);

Player player(m_window);
Enemy enemy(m_window);
std::deque<Projectile> projectileVector;

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

	// Escape key --> quit game
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{ m_window.close(); }
	
	// A key --> move player Left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) &&
		player.getPosX() >= player.getWidth() / 2.0f ||
		sf::Joystick::getAxisPosition(0, sf::Joystick::X) == -100 &&
		player.getPosX() >= player.getWidth() / 2.0f)
	{
		m_playerDirection = "Left";
	}

	// D key --> move player right
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) &&
		player.getPosX() <= m_windowWidth - player.getWidth() / 2.0f ||
		sf::Joystick::getAxisPosition(0, sf::Joystick::X) == 100 &&
		player.getPosX() <= m_windowWidth - player.getWidth() / 2.0f)
	{
		m_playerDirection = "Right";
	}
	else { m_playerDirection = "None"; }


	// Space bar --> Firing projectiles 
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
	{
		isFiring = true;
	}
}

void Game::update(float l_deltaTime)
{
	player.move(m_playerDirection, l_deltaTime);
	enemy.move(l_deltaTime);
	
	// check bullet 
	if (isFiring)
	{
		Projectile projectile(m_window);
		projectile.spawn(player.getPosX(), player.getPosY());
		projectileVector.push_back(projectile);
		isFiring = false;
		//std::cout << projectileVector.size() << std::endl;
	}

	for (size_t i = 0; i < projectileVector.size(); i++)
	{
		projectileVector[i].shoot(l_deltaTime);
		if (projectileVector[i].getPosY() <= 0 && projectileVector.size() > 0)
		{
			popBack = true;
		}
	}
	if (popBack)
	{
		if (projectileVector.size() > 0)
		{	
			projectileVector.pop_front();
			popBack = false;
			std::cout << projectileVector.size() << std::endl;
		}
	}
	
}

void Game::render()
{
	m_window.clear();

	for (size_t i = 0; i < projectileVector.size(); i++)
	{
		projectileVector[i].draw(m_window);
	}

	enemy.draw(m_window);
	player.draw(m_window);

	m_window.display();
}