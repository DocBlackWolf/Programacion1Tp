#pragma once
#include "libs.h"

class Clock
{

public:

	Clock(int Ltime,sf::Vector2f pos);
	void BackwardsCount();
	void Draw(std::unique_ptr<sf::RenderWindow>& _wnd);
	void SetTime(int Ltime);
	int TimeRemaining();


private:

	sf::Clock tickClock;
	sf::Font font;
	sf::Text text;
	std::string string;
	int time;
	
	


};

