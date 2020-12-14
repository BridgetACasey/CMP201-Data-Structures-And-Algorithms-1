//@BridgetACasey

#pragma once

#include "Grid.h"
#include "Graph.h"

class orderByMinF
{
public:
	bool operator()(const Node* lhs, const Node* rhs) const
	{
		return (lhs->f < rhs->f);
	}
};

class orderByMaxF
{
public:
	bool operator()(const Node* lhs, const Node* rhs) const
	{
		return (lhs->f > rhs->f);
	}
};

class AStar
{
public:
	AStar();
	~AStar();

	void setGrid(Grid* gd);

	void flood();
	void trace();

	int distanceBetween(Coordinate one, Coordinate two);

private:
	orderByMinF order;

	std::list<Coordinate> path;

	std::set<Node*, orderByMinF> openSet;
	std::set<Node*, orderByMaxF> closedSet;

	Node* startNode;
	Node* endNode;

	Grid* grid;
};