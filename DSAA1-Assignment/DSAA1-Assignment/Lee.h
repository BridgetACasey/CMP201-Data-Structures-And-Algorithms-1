//@BridgetACasey

#pragma once

#include <iostream>
#include <list>

struct Coord
{
	int x;
	int y;
};

class Lee
{
public:
	Lee();
	~Lee();

	void initGrid();
	void displayGrid();

	void floodGrid();
	void tracePath();

	void setPathOnGrid();
	void printPathCoords();

private:
	static const int WIDTH = 12;
	static const int HEIGHT = 12;

	int grid[HEIGHT][WIDTH] = {};

	Coord startCoord;
	Coord endCoord;

	std::list<Coord> path;
};