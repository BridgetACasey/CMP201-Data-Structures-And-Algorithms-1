//@BridgetACasey
#include "pch.h"
#include <SFML/Graphics.hpp>

#include "Grid.h"
#include "Graph.h"

#include "Lee.h"
#include "Dijkstra.h"
#include "AStar.h"

int main()
{
	srand((unsigned)time(0));

	Grid grid;
	Graph graph;

	Lee lee;
	Dijkstra dijkstra;
	AStar astar;

	dijkstra.setGrid(&grid);
	astar.setGrid(&grid);

	grid.populate();

	astar.flood();
	astar.trace();

	grid.renderNodeGrid();

	/*sf::RenderWindow window(sf::VideoMode(1600, 900), "Data Structures and Algorithms 1", sf::Style::Titlebar | sf::Style::Close);

	sf::Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
	}*/

	return 0;
}