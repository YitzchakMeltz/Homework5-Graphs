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
	map<Vertex, list<Vertex>>::iterator findVertex(const string& s);
	bool addVertexShell(string v);
	bool delVertexShell(string v);
	bool addEdgeShell(string s, string t);
	bool delEdgeShell(string s, string t);
	bool printNeighborsShell(string k);
	bool printFollowersShell(string k);
	bool printAllReachedShell(string k);
	bool printAll();
private:
	map<Vertex, list<Vertex>> graphMap;
};