#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Rules.h"

class Game
{
public:
	Game();
	~Game();
	void run();

private:
	void update(sf::Time t_dt);
	void render();
	void processEvents();
	void processKeys(sf::Event t_e);
	void processMouse(sf::Event t_e);
	void calculate();
	void positioning();
	void setup();

private:
	std::vector<sf::CircleShape> m_badGuys;
	std::vector<sf::CircleShape> m_goodGuys;
	sf::RenderWindow m_window;
	sf::Font m_font;
	sf::Text m_enemyCountT;
	sf::Text m_distanceT;
	sf::Text m_deployCountT;

private:
	float m_circleRadius;
	float m_distance;
	int m_enemyCount;
	int m_deployCount;

	const int MAX_BAD_GUYS = 30;
	const int MAX_GOOD_GUYS = 50;
	const int MAX_DISTANCE = 70;
};
#endif