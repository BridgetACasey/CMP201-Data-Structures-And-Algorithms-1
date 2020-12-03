//@BridgetACasey

#pragma once

#include <iostream>

struct Coordinate
{
	int x;
	int y;
};

struct Cell
{
	int flag;
};

class Grid
{
public:
	Grid();
	~Grid();

	void populate();
	void render();

	void setFlag(int x, int y, int flagValue);
	int getFlag(int x, int y);

	int getGridWidth();
	int getGridHeight();

private:
	static const int WIDTH = 16;
	static const int HEIGHT = 16;

	Cell grid[HEIGHT][WIDTH] = {};
};