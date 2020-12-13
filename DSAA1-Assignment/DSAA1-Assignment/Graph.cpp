//@BridgetACasey
#include "pch.h"
#include "Graph.h"

Graph::Graph()
{

}

Graph::~Graph()
{

}

void Graph::connect(Vertex& a, Vertex& b)
{
	a.neighbours.push_back(&b);
	b.neighbours.push_back(&a);
}

void Graph::display(std::list<Vertex*>& graph)
{
	for (auto v : graph)
	{
		std::cout << v->name << ": " << v->distance << std::endl;
	}
}

void Graph::test()
{
	Vertex va("A"), vb("B"), vc("C"), vd("D");

	connect(va, vb);
	connect(vb, vc);
	connect(va, vd);
	connect(vd, vc);
	
	vd.blocked = true;

	std::list<Vertex*> graph{ &va, &vb, &vc, &vd };
	
	display(graph);
}