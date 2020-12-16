//@BridgetACasey

#include "pch.h"
#include "Grid.h"

Grid::Grid()
{
	nodeGrid = nullptr;
}

Grid::~Grid()
{

}

void Grid::populate()
{
	populateNodeArray();

	int obstacleChance = 5;

	for (int y = 0; y < HEIGHT; ++y)
	{
		for (int x = 0; x < WIDTH; ++x)
		{
			nodeGrid[y][x].coordinate.x = x;
			nodeGrid[y][x].coordinate.y = y;

			int chance = 1 + (rand() % 100);

			if (chance <= obstacleChance)
			{
				nodeGrid[y][x].distance = (float)-2;
			}
		}
	}

	setNodeNeighbours();
}

void Grid::setNodeNeighbours()
{
	for (int y = 0; y < HEIGHT; ++y)
	{
		for (int x = 0; x < WIDTH; ++x)
		{
			if (y != HEIGHT - 1)
			{
				nodeGrid[y][x].neighbours.push_back(&nodeGrid[y + 1][x]);
			}

			if (x != WIDTH - 1)
			{
				nodeGrid[y][x].neighbours.push_back(&nodeGrid[y][x + 1]);
			}

			if (y != 0)
			{
				nodeGrid[y][x].neighbours.push_back(&nodeGrid[y - 1][x]);
			}

			if (x != 0)
			{
				nodeGrid[y][x].neighbours.push_back(&nodeGrid[y][x - 1]);
			}

			if (eightDirections)
			{
				if (y != 0 && x != 0)
				{
					nodeGrid[y][x].neighbours.push_back(&nodeGrid[y - 1][x - 1]);
				}

				if (y != 0 && x != WIDTH - 1)
				{
					nodeGrid[y][x].neighbours.push_back(&nodeGrid[y - 1][x + 1]);
				}

				if (y != HEIGHT - 1 && x != WIDTH - 1)
				{
					nodeGrid[y][x].neighbours.push_back(&nodeGrid[y + 1][x + 1]);
				}

				if (y != HEIGHT - 1 && x != 0)
				{
					nodeGrid[y][x].neighbours.push_back(&nodeGrid[y + 1][x - 1]);
				}
			}
		}
	}
}

void Grid::populateNodeArray()
{
	nodeGrid = new Node*[16];

	for (int i = 0; i < 16; ++i)
	{
		nodeGrid[i] = new Node[16];
	}
}

void Grid::renderNodeGrid()
{
	for (int y = 0; y < HEIGHT; ++y)
	{
		for (int x = 0; x < WIDTH; ++x)
		{
			std::cout << nodeGrid[y][x].distance << "	";
		}

		std::cout << std::endl;
	}
}

void Grid::setEightDirections(bool directions)
{
	eightDirections = directions;
}

float Grid::calculateManhattan(Coordinate one, Coordinate two)
{
	return(abs(two.x - one.x) + abs(two.y - one.y));
}

float Grid::calculateEuclidean(Coordinate one, Coordinate two)
{
	float x2 = abs((float)two.x - (float)one.x) * abs((float)two.x - (float)one.x);
	float y2 = abs((float)two.y - (float)one.x) * abs((float)two.y - (float)one.y);

	return sqrt(x2 + y2);
}

void Grid::setCellFlag(int x, int y, int flagValue)
{
	cellGrid[y][x].distance = flagValue;
}

int Grid::getCellFlag(int x, int y)
{
	return cellGrid[y][x].distance;
}

int Grid::getGridWidth()
{
	return WIDTH;
}

int Grid::getGridHeight()
{
	return HEIGHT;
}

Node** Grid::getNodeGrid()
{
	return nodeGrid;
}