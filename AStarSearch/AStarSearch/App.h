#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Node.h"

class App
{
public:
	App(sf::Vector2f screenDim, int tileSize, int rad);
	~App();

	void run();

	void initGrid();

private:

	sf::Vector2f m_screenDim;
	sf::RenderWindow m_window;
	std::vector<Node*> m_nodes;
	int m_tileSize;
	int m_agentRadius;

	std::vector<Node*> m_grid;
};

