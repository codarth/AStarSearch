#pragma once

#include <SFML/Graphics.hpp>

class Node
{
public:
	Node(int x, int y, Node* parent, int size, sf::Vector2f startPos);
	~Node();

	void buildTile();
	void setTileColor(sf::Color newColor);
	sf::VertexArray getTile() { return m_tile; }

private:
	float m_x;
	float m_y;
	int FValue;
	Node* m_parent;
	float m_GCost;
	float m_HCost;

	sf::VertexArray m_tile;
	sf::Vector2f m_startPos;
	int m_tileSize;


};

