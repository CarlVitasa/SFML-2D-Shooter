#pragma once

class Game
{
public:
	static Game &getInstance();
	void run();

private:
	Game();
	void processInput();
	void update(float deltaTime);
	void render();

};