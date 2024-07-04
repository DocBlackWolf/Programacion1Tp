#include "Block.h"

Block::Block()
{
    BTex.loadFromFile("Recursos/Imagenes/bloque_pared.png");
    Font.loadFromFile("Recursos/Fuentes/junegull.ttf");
    BSpr.setTexture(BTex);
  
    //Have to migrate most builder functionality to a separate class 

    text.setFont(Font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
}

void Block::Draw(std::unique_ptr<sf::RenderWindow>& _wnd) {
	_wnd->draw(BSpr);
    _wnd->draw(text);
	
}

void Block::setPosition(sf::Vector2f Pos)
{
    BSpr.setPosition(Pos);
}
