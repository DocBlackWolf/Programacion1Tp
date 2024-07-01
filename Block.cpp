#include "Block.h"

Block::Block(sf::Vector2f Pos, sf::Font font, std::string string)
{
    BTex.loadFromFile("Recursos/Imagenes/bloque_pared.png");
    BSpr.setTexture(BTex);
    BSpr.setPosition(Pos);

    text.setFont(font);
    text.setString(string);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
}

void Block::Draw(std::unique_ptr<sf::RenderWindow>& _wnd) {
	_wnd->draw(BSpr);
	_wnd->draw(text);
}
