//@BridgetACasey
#include "pch.h"
#include "Lee.h"

bool operator==(const Coordinate& lhs, const Coordinate& rhs)
{
	return (lhs.x == rhs.x && lhs.y == rhs.y);
}

Lee::Lee()
{
	grid = nullptr;

	startCoord.x = 1;
	startCoord.y = 1;

	endCoord.x = 4;
	endCoord.y = 4;
}

Lee::~Lee()
{

}

void Lee::setGrid(Grid* gd)
{
	grid = gd;
}

void Lee::flood()
{
	int distance = 0;
	int cellsUpdated = 0;

	bool searching = true;

	grid->setCellFlag(startCoord.x, startCoord.y, 0);

	while (searching)
	{
		for (int y = 0; y < grid->getGridHeight(); ++y)
		{
			for (int x = 0; x < grid->getGridWidth(); ++x)
			{
				if (grid->getCellFlag(x, y) == distance)
				{
					if (x == endCoord.x && y == endCoord.y)
					{
						searching = false;
					}

					if (y != grid->getGridHeight() - 1)
					{
						if (grid->getCellFlag(x, y + 1) == -1)
						{
							grid->setCellFlag(x, y + 1, distance + 1);
							++cellsUpdated;
						}
					}

					if (x != grid->getGridWidth() - 1)
					{
						if (grid->getCellFlag(x + 1, y) == -1)
						{
							grid->setCellFlag(x + 1, y, distance + 1);
							++cellsUpdated;
						}
					}

					if (y != 0)
					{
						if (grid->getCellFlag(x, y - 1) == -1)
						{
							grid->setCellFlag(x, y - 1, distance + 1);
							++cellsUpdated;
						}
					}

					if (x != 0)
					{
						if (grid->getCellFlag(x - 1, y) == -1)
						{
							grid->setCellFlag(x - 1, y, distance + 1);
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
		++distance;
	}
}

void Lee::trace()
{
	Coordinate currentCoord = endCoord;
	Coordinate nextCoord = currentCoord;

	int cellValue = grid->getGridHeight() + grid->getGridWidth();	//Max possible value

	while (true)
	{
		for (int y = 0; y < grid->getGridHeight(); ++y)
		{
			for (int x = 0; x < grid->getGridWidth(); ++x)
			{
				if (currentCoord.y == y && currentCoord.x == x)
				{
					if (y != grid->getGridHeight() - 1)
					{
						if (grid->getCellFlag(x, y + 1) < cellValue && grid->getCellFlag(x, y + 1) >= 0)
						{
							cellValue = grid->getCellFlag(x, y + 1);

							nextCoord.x = x;
							nextCoord.y = y + 1;
						}
					}

					if (x != grid->getGridWidth() - 1)
					{
						if (grid->getCellFlag(x + 1, y) < cellValue && grid->getCellFlag(x + 1, y) >= 0)
						{
							cellValue = grid->getCellFlag(x + 1, y);

							nextCoord.x = x + 1;
							nextCoord.y = y;
						}
					}

					if (y != 0)
					{
						if (grid->getCellFlag(x, y - 1) < cellValue && grid->getCellFlag(x, y - 1) >= 0)
						{
							cellValue = grid->getCellFlag(x, y - 1);

							nextCoord.x = x;
							nextCoord.y = y - 1;
						}
					}

					if (x != 0)
					{
						if (grid->getCellFlag(x - 1, y) < cellValue && grid->getCellFlag(x - 1, y) >= 0)
						{
							cellValue = grid->getCellFlag(x - 1, y);

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
	for (Coordinate cell : path)
	{
		grid->setCellFlag(cell.x, cell.y, -4);
	}

	grid->setCellFlag(endCoord.x, endCoord.y, -5);
}

void Lee::printPathCoords()
{
	std::cout << std::endl;

	for (Coordinate cell : path)
	{
		std::cout << "Coord: " << cell.x << "	" << cell.y << std::endl;
	}

	std::cout << std::endl;
}