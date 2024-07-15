#include "Block.h"

Block::Block()
{

    BTex.loadFromFile("Recursos/Imagenes/bloque_pared.png");
    Font.loadFromFile("Recursos/Fuentes/junegull.ttf");
    BSpr.setTexture(BTex);
    BSpr.setScale(1.4,1.4);
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
    BlockValue = std::rand() % 200;
    std::string random_number_str = std::to_string(BlockValue);
    text.setString(random_number_str);
}

void Block::setPosition(sf::Vector2f Pos)
{
    BSpr.setPosition(Pos);
    text.setPosition(Pos);
}

void Block::SwichStatus(bool bolean)
{
    if (bolean) {
        text.setFillColor(sf::Color::Green);
        Status = true;
        
    }
    else
    {
        text.setFillColor(sf::Color::White);
        Status = false;
    }
}

bool Block::GetStatus()
{
    return Status;
}

int Block::GetNumber()
{
    return BlockValue;
}

void Block::SetNumber(int Value)
{
    std::string ValueStr = std::to_string(Value);
    text.setString(ValueStr);
}

sf::FloatRect Block::GetBounds()
{
    return BSpr.getGlobalBounds();
}


