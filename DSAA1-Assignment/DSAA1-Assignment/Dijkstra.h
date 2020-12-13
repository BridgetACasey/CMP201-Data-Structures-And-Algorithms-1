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

/*
Mark all nodes unvisited.

Create a set of all the unvisited nodes called the unvisited set.

Assign to every node a tentative distance value: set it to zero for our initial node and to infinity for all other nodes.

Set the initial node as current.

For the current node, consider all of its unvisited neighbours and calculate their tentative distances through the current node.

Compare the newly calculated tentative distance to the current assigned value and assign the smaller one.
For example, if the current node A is marked with a distance of 6, and the edge connecting it with a neighbour B has length 2,
then the distance to B through A will be 6 + 2 = 8. If B was previously marked with a distance greater than 8 then change it to 8.
Otherwise, the current value will be kept.

When we are done considering all of the unvisited neighbours of the current node, mark the current node as visited and remove it
from the unvisited set. A visited node will never be checked again.

If the destination node has been marked visited (when planning a route between two specific nodes) or if the smallest tentative
distance among the nodes in the unvisited set is infinity (when planning a complete traversal; occurs when there is no connection
between the initial node and remaining unvisited nodes), then stop. The algorithm has finished.
Otherwise, select the unvisited node that is marked with the smallest tentative distance, set it as the new "current node", and go back to step 3.

When planning a route, it is actually not necessary to wait until the destination node is "visited" as above: the algorithm can
stop once the destination node has the smallest tentative distance among all "unvisited" nodes (and thus could be selected as
the next "current").
*/