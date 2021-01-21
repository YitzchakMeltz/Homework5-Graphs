#include"GraphElements.h"
#include<map>
#include<list>
#include <queue> 

#pragma once

using namespace std;

class Graph
{
public:
	Graph() {};
	~Graph() { graphMap.clear(); }
	bool vertexExist(string);
	void addVertexShell(string v);
	bool delVertexShell(string v);
	bool addEdgeShell(string s, string t);
	bool delEdgeShell(string s, string t);
	bool printNeighborsShell(string k);
	bool printFollowersShell(string k);
	void printAllReachedShell(string k);
	bool printAll();
private:
	map<string, Vertex> graphMap;
};