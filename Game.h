#pragma once
#include "Player.h"
#include "Block.h"
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
	Block blocks[5];
	

	float Grativy;





	


 

};

