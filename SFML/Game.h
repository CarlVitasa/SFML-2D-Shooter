#pragma once

class Game
{
public:
	Game();
	void Run();

private:
	void ProcessInput();
	void Update(double deltaTime);
	void Render();

};