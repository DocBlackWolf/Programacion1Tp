#include "Clock.h"

Clock::Clock(int Ltime, sf::Vector2f pos)
{
	time = Ltime;
	font.loadFromFile("Recursos/Fuentes/junegull.ttf");
	text.setFont(font);
	text.setFillColor(sf::Color::Cyan);
	text.setPosition(pos);
	text.setCharacterSize(60);

}

void Clock::BackwardsCount()
{
	if (tickClock.getElapsedTime().asSeconds() > 1 && time > 0)
	{
		time --;
		string = std::to_string(time);
		text.setString(string);
		tickClock.restart();
	}
	else if (time <= 0 )
	{
		string = "Game Ended";
		text.setString(string);
	}
}

void Clock::Draw(std::unique_ptr<sf::RenderWindow>& _wnd)
{
	_wnd->draw(text);
}

void Clock::SetTime(int Ltime)
{
	time = Ltime;
}

int Clock::TimeRemaining()
{
	return time;
}


