#include "Game.h"


Game::Game() : blocks{
		Block(sf::Vector2f(100, 420),"Block 1"),
		Block(sf::Vector2f(200, 420),"Block 2"),
		Block(sf::Vector2f(300, 420),"Block 3")
}
{
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

	for (int i = 0; i < 3; ++i) {
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
