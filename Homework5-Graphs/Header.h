#include"GraphElements.h"
#include<map>
#include<list>

#pragma once

using namespace std;

class Graph
{
public:
	Graph();
	~Graph();
	void addVertex(Vertex v);
	void delVertex(Vertex v);
	void addEdge(Edge e);
	void delEdge(Edge e);
private:
	map<Vertex, list<Vertex>> graphMap;
};