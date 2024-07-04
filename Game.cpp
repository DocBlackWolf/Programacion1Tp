#include "Game.h"


Game::Game() 
{
	blocks[0].setPosition(sf::Vector2f(20, 300));
	blocks[1].setPosition(sf::Vector2f(30, 300));
	blocks[2].setPosition(sf::Vector2f(40, 300));
	blocks[3].setPosition(sf::Vector2f(50, 300));
	blocks[4].setPosition(sf::Vector2f(60, 300));
	


	_wnd = std::make_unique<sf::RenderWindow>(sf::VideoMode(600, 600), "game window");
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

	for (int i = 0; i < 5; ++i) {
		std::cout << "Drawing block " << i << std::endl;
		blocks[i].Draw(_wnd);
	}

	_wnd->display();
	
}

void Game::Update(float delta)
{

	_player->Movement(delta);

}

void Game::ProcessEvents()
{
	sf::Event event;
	while (_wnd->pollEvent(event))
	{
	

		break;
	}
}
