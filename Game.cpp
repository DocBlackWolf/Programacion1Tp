#include "Game.h"


Game::Game()
{
	_wnd = std::make_unique<sf::RenderWindow>(sf::VideoMode(600, 600), "game window");
	_player = std::make_unique<Player>();
	Grativy = 0.001;

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
	_wnd->display();
	
}

void Game::Update(float delta)
{
	sf::Vector2f currentPos = _player->GetPos();
	currentPos.y += Grativy;
	_player->SetPos(currentPos);

}

void Game::ProcessEvents()
{
	sf::Event event;
	while (_wnd->pollEvent(event))
	{
		break;
	}
}
