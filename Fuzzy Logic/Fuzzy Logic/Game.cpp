#include "Game.h"

Game::Game() :
	m_window{ sf::VideoMode{800, 600, 32u}, "Fuzzy Logic"/*, sf::Style::None*/},
	m_circleRadius{7.0f}
{
	setup();
}

Game::~Game()
{
}

void Game::run()
{
	const float FPS = 60.0f;
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	sf::Time timePerFrame = sf::seconds(1.0f / FPS);

	while (m_window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();

		if (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents();
			update(timePerFrame);
		}
		render();
	}
}

void Game::update(sf::Time t_dt)
{
}

void Game::render()
{
	m_window.clear();

	for (int i = 0; i < m_enemyCount; i++)
	{
		m_window.draw(m_badGuys[i]);
	}
	for (int i = 0; i < m_deployCount; i++)
	{
		m_window.draw(m_goodGuys[i]);
	}

	std::cout << "Bad Guys: " << m_enemyCount << std::endl;
	std::cout << "Good Guys: " << m_deployCount << std::endl;

	m_window.display();
}

void Game::processEvents()
{
	sf::Event event;

	while (m_window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			m_window.close();
		}
		else if(sf::Event::KeyPressed == event.type)
		{
			processKeys(event);
		}
		else if (sf::Event::MouseButtonPressed == event.type)
		{
			processMouse(event);
		}
	}
}

void Game::processKeys(sf::Event t_e)
{
	if (sf::Keyboard::Escape == t_e.key.code)
	{
		m_window.close();		
	}
	else if(sf::Keyboard::Enter == t_e.key.code)
	{
		calculate();
	}
}

void Game::processMouse(sf::Event t_e)
{
	calculate();	
}

void Game::calculate()
{
	m_enemyCount = (rand() % MAX_BAD_GUYS) + 1;
	m_distance = (float)(rand() % MAX_DISTANCE) + 1;
	m_deployCount = Rules::getDeployCount(m_enemyCount, m_distance);
	positioning();
}

void Game::positioning()
{
	for (int i = 0; i < m_deployCount; i++)
	{
		m_goodGuys[i].setPosition(
							(rand() % (m_window.getSize().x / 2)),
							(rand() % m_window.getSize().y));
	}

	for (int i = 0; i < m_enemyCount; i++)
	{
		m_badGuys[i].setPosition(
							(rand() % (m_window.getSize().x / 2)) + (m_window.getSize().x / 2),
							(rand() % m_window.getSize().y));
	}
}

void Game::setup()
{
	sf::CircleShape m_circle;
	m_circle.setRadius(m_circleRadius);
	m_circle.setOrigin(m_circle.getRadius(), m_circle.getRadius());
	m_circle.setFillColor(sf::Color::Transparent);
	m_circle.setOutlineColor(sf::Color::Red);
	m_circle.setOutlineThickness(m_circle.getRadius() / 3.0f);
	m_circle.setPosition(0.0f, 0.0f);

	for (int i = 0; i < MAX_BAD_GUYS; i++)
	{
		m_badGuys.push_back(m_circle);
	}

	m_circle.setOutlineColor(sf::Color::Green);

	for (int i = 0; i < MAX_GOOD_GUYS; i++)
	{
		m_goodGuys.push_back(m_circle);
	}

	calculate();

	m_font.loadFromFile("Assets/Fonts/arial.ttf");
	m_enemyCountT.setFont(m_font);
	m_enemyCountT.setFillColor(sf::Color::Black);
	m_enemyCountT.setPosition(10, 50);
	m_enemyCountT.setString("Test");

	m_distanceT.setFont(m_font);
	m_distanceT.setFillColor(sf::Color::Black);
	m_distanceT.setPosition(10, 80);
	m_distanceT.setString("Test");

	m_deployCountT.setFont(m_font);
	m_deployCountT.setFillColor(sf::Color::Black);
	m_deployCountT.setPosition(10, 110);
	m_deployCountT.setString("Test");
}