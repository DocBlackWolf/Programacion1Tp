#pragma once
#include "libs.h"
class Block
{
public:
	Block();
	void Draw(std::unique_ptr<sf::RenderWindow>& _wnd);
	void RandomizeValue();
	void setPosition(sf::Vector2f Pos); 
	void SwichStatus();
	sf::FloatRect GetBounds();

private:
	sf::Texture BTex;
	sf::Sprite BSpr;
	sf::Font Font;
	sf::Text text;

};

