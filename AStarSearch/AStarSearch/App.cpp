#include "App.h"
#include <iostream>



App::App(sf::Vector2f screenDim, int tileSize, int rad) :
	m_screenDim(screenDim),
	m_window(sf::VideoMode(m_screenDim.x, m_screenDim.y), "A* Search"),
	m_tileSize(tileSize),
	m_agentRadius(rad)
{
}


App::~App()
{
}

void App::run() {
	m_window.clear(sf::Color::Black);

	initGrid();

	sf::Clock deltaClock;
	sf::Time dt = deltaClock.restart();;

	while (m_window.isOpen()) {
		sf::Event event;
		while (m_window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed: {
				m_window.close();
				break;
			}
			case sf::Event::KeyPressed:
				switch (event.key.code) {
				case sf::Keyboard::Escape: {
					m_window.close();
					break;
				}
				default:
					break;
				}

			case sf::Event::MouseButtonPressed: {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					std::cout << "Left Click!\n";
					sf::Vector2f buttonPressPos(event.mouseButton.x - m_agentRadius,
						event.mouseButton.y - m_agentRadius);
					std::cout << " x: " << buttonPressPos.x << " y: " << buttonPressPos.y << std::endl;
				}
				else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
					std::cout << "Right Click\n";
					sf::Vector2f buttonPressPos(event.mouseButton.x - m_agentRadius,
						event.mouseButton.y - m_agentRadius);
					std::cout << " x: " << buttonPressPos.x << " y: " << buttonPressPos.y << std::endl;
				}
			}
			default:
				break;
			}
		}

		for (int i = 0; i < m_nodes.size(); i++) {
			m_window.draw(m_nodes[i]->getTile());
		}

		m_window.display();

		dt = deltaClock.restart();

	}
}

void App::initGrid() {
	for (int i = 0; i < m_screenDim.x / m_tileSize; i++) {
		for (int j = 0; j < m_screenDim.y / m_tileSize; j++) {
			Node* newNode = new Node(i * m_tileSize, j * m_tileSize, 0, m_tileSize,
				sf::Vector2f(i*m_tileSize, j*m_tileSize));
			newNode->buildTile();
			newNode->setTileColor(sf::Color::Blue);
			m_nodes.push_back(newNode);
		}
	}
}
