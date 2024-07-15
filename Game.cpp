#include "Game.h"


Game::Game() 
{
	_wnd = std::make_unique<sf::RenderWindow>(sf::VideoMode(1000, 600), "game window");
	for (int i = 0; i < 10; ++i) {
		blocks[i].setPosition(sf::Vector2f(110 + 69 * i, 400));
		
	}
	RandomizeBlocks();
	_player = std::make_unique<Player>();
	_clock = std::make_unique<Clock>(60,sf::Vector2f(280,200));
	Grativy = 0.001f;
}

void Game::Loop()
{
	sf::Clock clock;
	clock.restart();
	float delta{};
	while (_wnd->isOpen())
	{

		delta = clock.restart().asSeconds();

		ProcessEvents();
		Draw();
		Update(delta);
	}
}

void Game::Draw()
{
	_wnd->clear(sf::Color::White);
	_clock->Draw(_wnd);
	_player->Draw(_wnd);

	for (int i = 0; i < 10; ++i) {
		//std::cout << "Drawing block " << i << std::endl;
		blocks[i].Draw(_wnd);
	}
	_wnd->display();
}

void Game::Update(float delta)
{
	_player->Movement(delta);
	_clock->BackwardsCount();

	//checks if the player interacted with the correct block and swiches states

	for (int i = 0; i < 10; ++i) 
	{


		if ((blocks[i].GetBounds().intersects(_player->GetBounds())) && lastInteraction.getElapsedTime().asSeconds() > 1)
		{
			

			if (StoredValues[ArrayPositon] == blocks[i].GetNumber() ) {
				blocks[i].SwichStatus(true);
				ArrayPositon++;
			}
			else if (StoredValues[ArrayPositon] != blocks[i].GetNumber()) {
				GameLost();
				
			}

			lastInteraction.restart();

		}


		if (blocks[i].GetStatus() == true)
		{
			allTrue++;
		}
		else if (blocks[i].GetStatus() == false)
		{
			allTrue--;
		}
		if (allTrue >= 10) {
			GameLost();
		}

	


	}
	

	///////////////////////////////////////////////////////////////////////////

	if (_clock->TimeRemaining() < 0) {
		GameLost();
	}

}

void Game::ProcessEvents()
{
	sf::Event event;
	while (_wnd->pollEvent(event))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
			RandomizeBlocks();
			_clock->SetTime(60);
			_player->SetPos(sf::Vector2f(400, 400));
		}
		break;
	}
}

void Game::RandomizeBlocks()
{
	for (int i = 0; i < 10; ++i) {
		blocks[i].RandomizeValue();
		blocks[i].SwichStatus(false);
		StoredValues[i] = blocks[i].GetNumber();
	}
	BubbleSort(StoredValues, 10);
}

void Game::GameLost()
{
	for (int i = 0; i < 10; ++i) {

			blocks[i].SetNumber(StoredValues[i]);
			blocks[i].SwichStatus(false);
			_clock->SetTime(0);
	}
}

void Game::BubbleSort(int arr[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}
