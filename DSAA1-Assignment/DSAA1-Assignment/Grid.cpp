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
				cellGrid[y][x].distance = -2;
				nodeGrid[y][x].distance = -2;
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

void Grid::renderCellGrid()
{
	for (int y = 0; y < HEIGHT; ++y)
	{
		for (int x = 0; x < WIDTH; ++x)
		{
			std::cout << cellGrid[y][x].distance << "	";
		}

		std::cout << std::endl;
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

void Grid::setCellFlag(int x, int y, int flagValue)
{
	cellGrid[y][x].distance = flagValue;
}

int Grid::getCellFlag(int x, int y)
{
	return cellGrid[y][x].distance;
}

void Grid::setNodeFlag(int x, int y, int flagValue)
{
	nodeGrid[y][x].distance = flagValue;
}

int Grid::getNodeFlag(int x, int y)
{
	return nodeGrid[y][x].distance;
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