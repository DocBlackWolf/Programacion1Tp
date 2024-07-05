#include "Block.h"

Block::Block()
{

    BTex.loadFromFile("Recursos/Imagenes/bloque_pared.png");
    Font.loadFromFile("Recursos/Fuentes/junegull.ttf");
    BSpr.setTexture(BTex);
    BSpr.setScale(1.2,1.2);
    text.setFont(Font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);
}

void Block::Draw(std::unique_ptr<sf::RenderWindow>& _wnd) {
	_wnd->draw(BSpr);
    _wnd->draw(text);
	
}

void Block::RandomizeValue()
{
    int random_number = std::rand() % 200;
    std::string random_number_str = std::to_string(random_number);
    text.setString(random_number_str);
}

void Block::setPosition(sf::Vector2f Pos)
{
    BSpr.setPosition(Pos);
    text.setPosition(Pos);
}

void Block::SwichStatus()
{
    text.setFillColor(sf::Color::Green);
}

sf::FloatRect Block::GetBounds()
{
    return BSpr.getGlobalBounds();
}


