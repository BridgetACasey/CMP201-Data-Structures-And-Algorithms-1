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
	int distance = -1;
};

struct Node
{
	bool visited = false;

	int cost = 1;
	int distance = -1;

	int f = 0;	//Sum of g and h, which is an estimate of total path length
	int g = 0;	//Accumulated cost from start node to current node
	int h = 0;	//Estimated cost from current node to end node

	Coordinate coordinate = {0, 0};

	Node* parent = nullptr;
	std::list<Node*> neighbours;
};

class Grid
{
public:
	Grid();
	~Grid();

	void populate();
	void setNodeNeighbours();
	void populateNodeArray();

	void renderCellGrid();
	void renderNodeGrid();

	void setCellFlag(int x, int y, int flagValue);
	int getCellFlag(int x, int y);

	void setNodeFlag(int x, int y, int flagValue);
	int getNodeFlag(int x, int y);

	int getGridWidth();
	int getGridHeight();

	Node** getNodeGrid();

private:
	static const int WIDTH = 12;
	static const int HEIGHT = 12;

	Cell cellGrid[HEIGHT][WIDTH] = {};

	Node** nodeGrid;
};