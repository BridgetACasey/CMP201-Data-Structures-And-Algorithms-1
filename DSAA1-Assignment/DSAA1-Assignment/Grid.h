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

	float cost = 1;
	float distance = -1;

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

	void renderNodeGrid();

	void setEightDirections(bool directions);

	void setCellFlag(int x, int y, int flagValue);
	int getCellFlag(int x, int y);

	float calculateManhattan(Coordinate one, Coordinate two);
	float calculateEuclidean(Coordinate one, Coordinate two);

	int getGridWidth();
	int getGridHeight();

	Node** getNodeGrid();

private:
	static const int WIDTH = 12;
	static const int HEIGHT = 12;

	Cell cellGrid[HEIGHT][WIDTH] = {};

	Node** nodeGrid;

	bool eightDirections = false;
};