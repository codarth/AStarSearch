#include "Node.h"



Node::Node(int x, int y, Node* parent, int size, sf::Vector2f startPos) :
	m_x(x),
	m_y(y),
	m_parent(parent),
	m_tileSize(size),
	m_startPos(startPos)
{
}


Node::~Node()
{
}

void Node::buildTile() {
	m_tile.setPrimitiveType(sf::Quads);
	m_tile.append(sf::Vector2f(m_startPos.x, m_startPos.y));
	m_tile.append(sf::Vector2f(m_startPos.x + m_tileSize, m_startPos.y));
	m_tile.append(sf::Vector2f(m_startPos.x + m_tileSize, m_startPos.y + m_tileSize));
	m_tile.append(sf::Vector2f(m_startPos.x, m_startPos.y + m_tileSize));
}

void Node::setTileColor(sf::Color newColor) {
	for (int i = 0; i < 4; i++) {
		//m_tile[0].color = sf::Color::Blue;
		//m_tile[1].color = sf::Color::Red;
		//m_tile[2].color = sf::Color::Blue;
		//m_tile[3].color = sf::Color::Blue;
		m_tile[i].color = newColor;
	}
}
