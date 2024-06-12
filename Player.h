#pragma once
#include "libs.h"

class Player
{
public:
	Player();
	void Movement(float Delta);
	void Draw(std::unique_ptr<sf::RenderWindow>& _wnd);

private:
	sf::Texture playerText;
	sf::Sprite playerSpr;
};

