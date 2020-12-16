//@BridgetACasey

#include "pch.h"
#include "AStar.h"

AStar::AStar()
{
	grid = nullptr;

	startNode = nullptr;
	endNode = nullptr;
}

void AStar::setGrid(Grid* gd)
{
	grid = gd;
}

void AStar::flood()
{
	startNode = &grid->getNodeGrid()[0][0];
	endNode = &grid->getNodeGrid()[11][11];

	Node* currentNode = startNode;

	startNode->distance = 0;
	startNode->g = 0;

	//startNode->f = startNode->g + grid->calculateManhattan(startNode->coordinate, endNode->coordinate) + 1;
	startNode->f = startNode->g + grid->calculateEuclidean(startNode->coordinate, endNode->coordinate) + 1;
	//Adding 1, otherwise f value is the same as its neighbours and it never gets added to the closed set

	openSet.insert(currentNode);

	while (!openSet.empty())
	{
		if (currentNode == endNode)
		{
			std::cout << "FOUND!" << std::endl;
			break;
		}

		currentNode = *openSet.begin();

		closedSet.insert(currentNode);
		openSet.erase(currentNode);

		for (Node* neighbour : currentNode->neighbours)
		{
			neighbour->parent = currentNode;

			std::set<Node*>::iterator nodeExists = closedSet.find(neighbour);	//Check if the node is on the closed set already

 			if (nodeExists == closedSet.end())
			{
				if (neighbour->distance != -2)
				{
					//neighbour->h = grid->calculateManhattan(neighbour->coordinate, endNode->coordinate);
					neighbour->h = grid->calculateEuclidean(neighbour->coordinate, endNode->coordinate);

					//neighbour->g = neighbour->g + grid->calculateManhattan(neighbour->coordinate, neighbour->parent->coordinate);
					neighbour->g = neighbour->g + grid->calculateEuclidean(neighbour->coordinate, neighbour->parent->coordinate);

					neighbour->f = neighbour->g + neighbour->h;

					//neighbour->distance = grid->calculateManhattan(neighbour->coordinate, startNode->coordinate);
					neighbour->distance = grid->calculateEuclidean(neighbour->coordinate, startNode->coordinate);

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