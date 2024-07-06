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
	void RandomizeBlocks(); //holder function to organize anothers
	void BubbleSort(int arr[], int n); //Sorting function to organize an array

	std::unique_ptr<sf::RenderWindow> _wnd; //main, unique pointer allows for it to be deleted once its out of context
	std::unique_ptr<Player> _player; //player, unique pointer allows for it to be deleted once its out of context
	Block blocks[10]; //object array of blocks
	int StoredValues[10]; //stores the organized values of block
	int ArrayPositon; //stores the array position so it can be access by all members
	

	float Grativy;

};

