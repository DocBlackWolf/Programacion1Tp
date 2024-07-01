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
	static const int arraySize = 3;
	Block blocks[arraySize] = {
		Block(sf::Vector2f(100, 100), Mfont, "Block 1"),
		Block(sf::Vector2f(200, 100), Mfont, "Block 2"),
		Block(sf::Vector2f(300, 100), Mfont, "Block 3")
		
	};
	
	float Grativy;
	sf::Font Mfont; //main font


 

};

