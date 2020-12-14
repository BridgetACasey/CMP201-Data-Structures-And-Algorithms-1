//@BridgetACasey

#include "pch.h"
#include "AStar.h"

AStar::AStar()
{
	grid = nullptr;

	startNode = nullptr;
	endNode = nullptr;
}

AStar::~AStar()
{

}

void AStar::setGrid(Grid* gd)
{
	grid = gd;
}

void AStar::flood()
{
	startNode = &grid->getNodeGrid()[0][0];
	endNode = &grid->getNodeGrid()[11][11];

	Node* currentNode = nullptr;

	bool found = false;

	startNode->distance = 0;
	startNode->g = 0;
	startNode->f = startNode->g + distanceBetween(startNode->coordinate, endNode->coordinate);

	openSet.insert(startNode);

	while (!openSet.empty())
	{
		currentNode = *openSet.begin();

		if (currentNode == endNode)
		{
			found = true;
			std::cout << "FOUND!1!" << std::endl;
			endNode->distance = -5;
			break;
		}

		closedSet.insert(currentNode);
		openSet.erase(currentNode);

		for (Node* neighbour : currentNode->neighbours)
		{
			std::set<Node*>::iterator nodeExists = closedSet.find(neighbour);	//Check if the node is on the closed set already

 			if (nodeExists == closedSet.end())
			{
				if (neighbour->distance != -2)
				{
					neighbour->parent = currentNode;

					neighbour->h = distanceBetween(neighbour->coordinate, endNode->coordinate);
					neighbour->g = neighbour->g + distanceBetween(neighbour->coordinate, neighbour->parent->coordinate);
					neighbour->f = neighbour->g + neighbour->h;

					neighbour->distance = distanceBetween(neighbour->coordinate, startNode->coordinate);

					openSet.insert(neighbour);
				}
			}
		}
	}
}

void AStar::trace()
{
	for (Node* current : closedSet)
	{
		path.push_back(current->coordinate);

		current = current->parent;
	}

	for (Coordinate coord : path)
	{
		std::cout << "Coord: " << coord.x << " " << coord.y << std::endl;
	}
}

int AStar::distanceBetween(Coordinate one, Coordinate two)
{
	return(abs(two.x - one.x) + abs(two.y - one.y));
}