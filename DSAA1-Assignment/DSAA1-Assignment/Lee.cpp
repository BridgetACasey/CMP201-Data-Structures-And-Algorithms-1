//@BridgetACasey

#include "Lee.h"

bool operator==(const Coord& lhs, const Coord& rhs)
{
	return (lhs.x == rhs.x && lhs.y == rhs.y);
}

Lee::Lee()
{
	startCoord.x = 1;
	startCoord.y = 1;

	endCoord.x = 4;
	endCoord.y = 4;
}

Lee::~Lee()
{

}

void Lee::initGrid()
{
	int passMark = 25;

	for (int y = 0; y < HEIGHT; ++y)
	{
		for (int x = 0; x < WIDTH; ++x)
		{
			int chance = 1 + (rand() % 100);

			if (chance <= passMark)
			{
				grid[y][x] = -2;
			}
			
			else
			{
				grid[y][x] = -1;
			}
		}
	}
}

void Lee::displayGrid()
{
	for (int y = 0; y < HEIGHT; ++y)
	{
		for (int x = 0; x < WIDTH; ++x)
		{
			std::cout << grid[y][x] << "	";
		}

		std::cout << std::endl;
	}
}

void Lee::floodGrid()
{
	int searchCount = 0;
	int cellsUpdated = 0;

	bool searching = true;

	grid[startCoord.y][startCoord.x] = 0;

	while (searching)
	{
		for (int y = 0; y < HEIGHT; ++y)
		{
			for (int x = 0; x < WIDTH; ++x)
			{
				if (grid[y][x] == searchCount)
				{
					if (x == endCoord.x && y == endCoord.y)
					{
						searching = false;
					}

					if (y != HEIGHT - 1)
					{
						if (grid[y + 1][x] == -1)
						{
							grid[y + 1][x] = searchCount + 1;
							++cellsUpdated;
						}
					}

					if (x != WIDTH - 1)
					{
						if (grid[y][x + 1] == -1)
						{
							grid[y][x + 1] = searchCount + 1;
							++cellsUpdated;
						}
					}

					if (y != 0)
					{
						if (grid[y - 1][x] == -1)
						{
							grid[y - 1][x] = searchCount + 1;
							++cellsUpdated;
						}
					}

					if (x != 0)
					{
						if (grid[y][x - 1] == -1)
						{
							grid[y][x - 1] = searchCount + 1;
							++cellsUpdated;
						}
					}
				}
			}
		}

		if (cellsUpdated == 0)
		{
			searching = false;
		}

		cellsUpdated = 0;
		++searchCount;
	}
}

void Lee::tracePath()
{
	Coord currentCoord = endCoord;
	Coord nextCoord = currentCoord;

	int cellValue = HEIGHT + WIDTH;	//Max possible value

	while (true)
	{
		for (int y = 0; y < HEIGHT; ++y)
		{
			for (int x = 0; x < WIDTH; ++x)
			{
				if (currentCoord.y == y && currentCoord.x == x)
				{
					if (y != HEIGHT - 1)
					{
						if (grid[y + 1][x] < cellValue && grid[y + 1][x] >= 0)
						{
							cellValue = grid[y + 1][x];

							nextCoord.x = x;
							nextCoord.y = y + 1;
						}
					}

					if (x != WIDTH - 1)
					{
						if (grid[y][x + 1] < cellValue && grid[y][x + 1] >= 0)
						{
							cellValue = grid[y][x + 1];

							nextCoord.x = x + 1;
							nextCoord.y = y;
						}
					}

					if (y != 0)
					{
						if (grid[y - 1][x] < cellValue && grid[y - 1][x] >= 0)
						{
							cellValue = grid[y - 1][x];

							nextCoord.x = x;
							nextCoord.y = y - 1;
						}
					}

					if (x != 0)
					{
						if (grid[y][x - 1] < cellValue && grid[y][x - 1] >= 0)
						{
							cellValue = grid[y][x - 1];

							nextCoord.x = x - 1;
							nextCoord.y = y;
						}
					}
				}
			}
		}

		currentCoord = nextCoord;

		if (currentCoord == startCoord)
		{
			break;
		}

		path.push_back(currentCoord);
	}
}

void Lee::setPathOnGrid()
{
	for (Coord cell : path)
	{
		grid[cell.y][cell.x] = -4;
	}

	grid[endCoord.y][endCoord.x] = -5;
}

void Lee::printPathCoords()
{
	std::cout << std::endl;

	for (Coord cell : path)
	{
		std::cout << "Coord: " << cell.x << "	" << cell.y << std::endl;
	}

	std::cout << std::endl;
}