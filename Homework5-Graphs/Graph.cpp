#include "Graph.h"

bool Graph::vertexExist(string s)
{
	map<string, Vertex>::iterator it;

	for (it = graphMap.begin(); it != graphMap.end(); it++)
		if (it->first == s)
			return true;

	return false;
}

bool Graph::addVertexShell(string v)
{
	graphMap.insert({ v,Vertex(v) });
}

bool Graph::delVertexShell(string v)
{
	Vertex* temp = &graphMap[v];

	map<string, Vertex>::iterator it;

	//find and remove all edges to our Vertex
	for (it = graphMap.begin(); it != graphMap.end(); it++)
	{
		if (it->second.targetExist(temp))
			it->second.removeEdge(Edge(temp));
	}

	graphMap.erase(v);			//erases that Vertex from the map
}

bool Graph::addEdgeShell(string s, string t)
{
	if (!vertexExist(s))
		throw "Error. Source vertex does not exist.\n";

	if (!vertexExist(t))
		throw "Error. Target vertex does not exist.\n";

	if (graphMap[s].edgeExist(t))
		throw "ERROR. Edge already exist.\n";

	graphMap[s].addEdge(&graphMap[t]);
}

bool Graph::delEdgeShell(string s, string t)
{
	if (!vertexExist(s))
		throw "Error. Source vertex does not exist.\n";

	if (!vertexExist(t))
		throw "Error. Target vertex does not exist.\n";

	if (!graphMap[s].edgeExist(t))
		throw "ERROR. Edge does not exist.\n";

	graphMap[s].removeEdge(Edge(&graphMap[t]));
}


//given Vertex v, prints all vertices u that have an edge from v to u
bool Graph::printNeighborsShell(string k)
{
	if (!vertexExist(k))
		throw "Error. Source vertex does not exist.\n";

	list<Edge>::iterator it;

	for (it = graphMap[k].EdgeList.begin(); it != graphMap[k].EdgeList.end(); it++)
		cout << it->target->Key << endl;
}

bool Graph::printFollowersShell(string k)
{
	map<string, Vertex>::iterator it;

	for (it = graphMap.begin(); it != graphMap.end(); it++)
	{
		list<Edge>::iterator jt;

		for (jt = it->second.EdgeList.begin(); jt != it->second.EdgeList.end(); it++)
			if (jt->target == &graphMap[k])
				cout << it->first << endl;
	}
}