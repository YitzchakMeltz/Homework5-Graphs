#include<string>
#include <list>
#include<iostream>

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
	bool removeEdge(Edge);
	int numOfNeighbors();
	bool targetExist(Vertex* v);
	bool edgeExist(string);
	bool operator==(Vertex& v);
	void print()const;
	friend class Graph;
private:
	string Key;
	Color color;
	list<Edge> EdgeList;
};