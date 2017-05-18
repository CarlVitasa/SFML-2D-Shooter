#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <SFML\Graphics.hpp>
#include "Player.h"
#include "Enemy.h"

class Game
{
public:
	static Game& getInstance();
	void runGameLoop();

private:
	Game();
	void processInput();
	void update(float l_deltaTime);
	void render();

};