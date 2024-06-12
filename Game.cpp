#include "Game.h"

Game::Game()
{
	_wnd = std::make_unique<sf::RenderWindow>(sf::VideoMode(600, 600), "game window");

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
	_wnd->display();
}

void Game::Update(float delta)
{


}

void Game::ProcessEvents()
{
	sf::Event event;
	while (_wnd->pollEvent(event))
	{
		break;
	}
}
