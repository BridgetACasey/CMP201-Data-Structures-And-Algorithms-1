//@BridgetACasey

#pragma once

#include "Grid.h"
#include "Graph.h"

class Lee
{
public:
	Lee();
	~Lee();

	void setGrid(Grid* gd);

	void flood();
	void trace();

	void setPathOnGrid();
	void printPathCoords();

private:
	Coordinate startCoord;
	Coordinate endCoord;

	std::list<Coordinate> path;

	Grid* grid;
};