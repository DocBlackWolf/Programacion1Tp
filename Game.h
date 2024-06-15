#pragma once
#include "Player.h"
#include "libs.h"

class Game
{

public:
	Game();
	void Loop();

private:

	void Draw();
	void Update(float delta);
	void ProcessEvents();

	std::unique_ptr<sf::RenderWindow> _wnd;
	std::unique_ptr<Player> _player;
	float Grativy;


 

};

