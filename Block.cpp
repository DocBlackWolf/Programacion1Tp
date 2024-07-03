#include "Block.h"

Block::Block(sf::Vector2f Pos,std::string string)
{
    BTex.loadFromFile("Recursos/Imagenes/bloque_pared.png");
    Font.loadFromFile("Recursos/Fuentes/junegull.ttf");
    BSpr.setTexture(BTex);
    BSpr.setPosition(Pos);

    text.setFont(Font);
    text.setString(string);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
}

void Block::Draw(std::unique_ptr<sf::RenderWindow>& _wnd) {
	_wnd->draw(BSpr);
	_wnd->draw(text);
}
