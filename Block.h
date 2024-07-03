#pragma once
#include "libs.h"
class Block
{
public:
	Block(sf::Vector2f Pos,std::string string);
	void Draw(std::unique_ptr<sf::RenderWindow>& _wnd);
private:
	sf::Texture BTex;
	sf::Sprite BSpr;
	sf::Font Font;
	sf::Text text;
};

