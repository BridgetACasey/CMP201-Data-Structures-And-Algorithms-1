//@BridgetACasey

#pragma once

#include "Grid.h"
#include "Graph.h"

class Dijkstra
{
public:
	Dijkstra();
	~Dijkstra();

	void setGrid(Grid* gd);

	void flood();
	void trace();

private:
	std::list<Coordinate> path;

	Node* startNode;
	Node* endNode;

	Grid* grid;
};