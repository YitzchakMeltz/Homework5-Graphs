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
	bool operator==(const Edge& e) const;

	//fields
	Vertex* target;
};

//enum class Color {White,Gray,Black};

class Vertex
{
public:
	Vertex() { reached = false; }
	Vertex(string key);
	void addEdge(Edge);
	bool removeEdge(Edge);
	int numOfNeighbors();
	bool targetExist(Vertex* v);
	bool edgeExist(string);
	bool operator==(Vertex& v);
	void print();
	friend class Graph;
private:
	string Key;
	bool reached;
	//Color color=Color::White;
	list<Edge> EdgeList;
};