//@BridgetACasey

#pragma once

#include <iostream>
#include <list>

struct Vertex
{
	std::string name;
	bool blocked;
	int distance;	// -1 if not filled in yet
	std::list<Vertex*>neighbours;
	Vertex(std::string name_) : name(name_), blocked(false), distance(-1) {}
};

class Graph
{
public:
	Graph();
	~Graph();

	void connect(Vertex& a, Vertex& b);
	void display(std::list<Vertex*>& graph);
	void test();
};