//@BridgetACasey

#pragma once

#include <iostream>
#include <list>

#include "Grid.h"

struct Coord
{
	int x;
	int y;
};

struct Vertex
{
	std::string name;
	bool blocked;
	int distance;	// -1 if not filled in yet
	std::list<Vertex *>neighbours;
	Vertex(std::string name_): name(name_), blocked(false), distance(-1) {}
};

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
	Coord startCoord;
	Coord endCoord;

	std::list<Coord> path;

	Grid* grid;
};