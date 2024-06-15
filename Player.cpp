#include "Player.h"

Player::Player()
{
	playerText.loadFromFile("Recursos/Imagenes/jumper.png");
	playerSpr.setTexture(playerText);

}

void Player::Movement(float Delta)
{

}

void Player::Draw(std::unique_ptr<sf::RenderWindow>& _wnd)
{
	playerSpr.setPosition(PlayerPos);
	_wnd->draw(playerSpr);
}

void Player::SetPos(sf::Vector2f Pos)
{
	Pos = PlayerPos;
}

sf::Vector2f Player::GetPos() const
{

	return PlayerPos;
}
