//@BridgetACasey

#include "Grid.h"

Grid::Grid()
{

}

Grid::~Grid()
{

}

void Grid::populate()
{
	int obstacleChance = 25;

	for (int y = 0; y < HEIGHT; ++y)
	{
		for (int x = 0; x < WIDTH; ++x)
		{
			int chance = 1 + (rand() % 100);

			if (chance <= obstacleChance)
			{
				grid[y][x].flag = -2;
			}

			else
			{
				grid[y][x].flag = -1;
			}
		}
	}
}

void Grid::render()
{
	for (int y = 0; y < HEIGHT; ++y)
	{
		for (int x = 0; x < WIDTH; ++x)
		{
			std::cout << grid[y][x].flag << "	";
		}

		std::cout << std::endl;
	}
}

void Grid::setFlag(int x, int y, int flagValue)
{
	grid[y][x].flag = flagValue;
}

int Grid::getFlag(int x, int y)
{
	return grid[y][x].flag;
}

int Grid::getGridWidth()
{
	return WIDTH;
}

int Grid::getGridHeight()
{
	return HEIGHT;
}