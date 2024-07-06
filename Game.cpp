#include "Game.h"


Game::Game() 
{
	_wnd = std::make_unique<sf::RenderWindow>(sf::VideoMode(1000, 600), "game window");
	for (int i = 0; i < 10; ++i) {
		blocks[i].setPosition(sf::Vector2f(100 + 60 * i, 410));
		
	}
	RandomizeBlocks();
	_player = std::make_unique<Player>();
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


	for (int i = 0; i < 10; ++i) {



		if (blocks[i].GetBounds().intersects(_player->GetBounds()) && StoredValues[ArrayPositon] == blocks[i].GetNumber()) {
			blocks[i].SwichStatus(true);
			ArrayPositon++;
		}


	}


}

void Game::ProcessEvents()
{
	sf::Event event;
	while (_wnd->pollEvent(event))
	{
		break;
	}
}

void Game::RandomizeBlocks()
{
	for (int i = 0; i < 10; ++i) {
		blocks[i].RandomizeValue();
		StoredValues[i] = blocks[i].GetNumber();
	}
	BubbleSort(StoredValues, 10);
	for (int i = 0; i < 10; ++i) {
		std::cout << StoredValues[i] << " ";
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
