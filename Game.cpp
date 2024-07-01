#include "Game.h"


Game::Game()
{
	_wnd = std::make_unique<sf::RenderWindow>(sf::VideoMode(600, 600), "game window");

	if (!Mfont.loadFromFile("Recursos/Fuentes/comic.ttf")) {
		std::cerr << "Failed to load font\n";
		throw std::runtime_error("Failed to load font");
	}
	else {
		std::cout << "Font loaded successfully\n";
	}

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
