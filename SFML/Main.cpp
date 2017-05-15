#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Player.h"

int main()
{
	Game& game = Game::getInstance();
	game.run();
	return 0;
}

