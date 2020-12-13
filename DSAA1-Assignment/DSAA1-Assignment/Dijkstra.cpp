//@BridgetACasey
#include "pch.h"
#include "Dijkstra.h"

//Functor - Used for the queue comparison.
struct VertexMax
{
	bool operator() (const Vertex* v1, const Vertex* v2) const
	{
		return (v1->distance > v2->distance);
	}
};

struct NodeMax
{
	bool operator() (const Node* node1, const Node* node2) const
	{
		return (node1->distance > node2->distance);
	}
};

Dijkstra::Dijkstra()
{
	grid = nullptr;

	startNode = nullptr;
	endNode = nullptr;
}

Dijkstra::~Dijkstra()
{

}

void Dijkstra::setGrid(Grid* gd)
{
	grid = gd;
}

void Dijkstra::flood()
{
	std::priority_queue<Node*, std::vector<Node*>, NodeMax> nodeQueue;

	startNode = &grid->getNodeGrid()[2][2];
	endNode = &grid->getNodeGrid()[6][6];

	startNode->distance = 0;

	bool found = false;

	nodeQueue.push(startNode);

	while (!nodeQueue.empty())
	{
		if (found)
		{
			break;
		}

		for (auto& currentNode : nodeQueue.top()->neighbours)
		{
			if (!currentNode->visited)
			{
				if (currentNode->distance != -2)
				{
					currentNode->distance = nodeQueue.top()->distance + currentNode->cost;

					nodeQueue.push(currentNode);

					if (currentNode == endNode)
					{
						found = true;
					}
				}
			}
		}

		nodeQueue.top()->visited = true;
		nodeQueue.pop();
	}
}

void Dijkstra::trace()
{
	Node* currentNode = endNode;
	Node* nextNode = currentNode;

	while (true)
	{
		path.push_back(currentNode->coordinate);

		if (currentNode == startNode)
		{
			break;
		}

		for (Node *neighbour : currentNode->neighbours)
		{
			if (neighbour->distance > -1)
			{
				if (neighbour->distance < nextNode->distance)
				{
					nextNode = neighbour;
				}
			}
		}

		currentNode = nextNode;
	}

	endNode->distance = -5;
}