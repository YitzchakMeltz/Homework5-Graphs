#include<string>
#include <list>

#pragma once

using namespace std;

class Vertex;

class Edge
{
public:
	Edge(Vertex* t);
	bool operator==(Edge& e);

	//fields
	Vertex* target;
};

enum class Color {White,Gray,Black};

class Vertex
{
public:
	Vertex(string key);
	void addEdge(Edge);
	int numOfNeighbors();
	bool targetExist(Vertex* v);
	bool operator==(Vertex& v);
private:
	string Key;
	Color color;
	list<Edge> EdgeList;
};