#pragma once
#include "libs.h"

class Player
{
public:
	Player();
	void Movement(float Delta);
	void Draw(std::unique_ptr<sf::RenderWindow>& _wnd);
	void SetPos(sf::Vector2f Pos);
	sf::Vector2f GetPos() const;

private:
	sf::Texture playerText;
	sf::Sprite playerSpr;
	sf::Vector2f PlayerPos;
};

