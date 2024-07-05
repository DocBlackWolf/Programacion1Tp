#include "Player.h"

Player::Player()
{
	playerText.loadFromFile("Recursos/Imagenes/jumper.png"); 
	playerSpr.setTexture(playerText);
	PlayerPos.x = 100;
	PlayerPos.y = 500;
	JumpSpeed = 800;
	Jumped = false;


}

void Player::Movement(float Delta)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		PlayerPos.x += 150.0 * Delta;

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		PlayerPos.x -= 150.0 * Delta;

	}

	PlayerPos.y += 300 * Delta;
	if (PlayerPos.y > 500) {
		PlayerPos.y = 500;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && Jumped == false ) {
		PlayerPos.y -= 50.0;
		Jumped = true;
		TSJ.restart();
	}

	if (TSJ.getElapsedTime().asMilliseconds() > 500) {
		Jumped = false;
	}
}

void Player::Draw(std::unique_ptr<sf::RenderWindow>& _wnd)
{
	playerSpr.setPosition(PlayerPos);
	_wnd->draw(playerSpr);


}

void Player::SetPos(sf::Vector2f Pos)
{
	PlayerPos = Pos;
}



sf::Vector2f Player::GetPos() const
{

	return PlayerPos;
}

sf::FloatRect Player::GetBounds()
{
	return playerSpr.getGlobalBounds();
}
