#include "Graph.h"


//function checks if there exists a Vertex in the graph who's key matches the given string
bool Graph::vertexExist(string s)
{
	map<string, Vertex>::iterator it;

	for (it = graphMap.begin(); it != graphMap.end(); it++)
		if (it->first == s)
			return true;

	return false;
}


//function adds a Vertex from to graph
void Graph::addVertexShell(string v)
{
	graphMap.insert({ v,Vertex(v) });
}


//function deletes a Vertex from the graph
bool Graph::delVertexShell(string v)
{
	if (!vertexExist(v))
		return false;

	Vertex* temp = &graphMap[v];			//create a pointer to the Vertex with the key that matches the given string

	map<string, Vertex>::iterator it;

	//find and remove all edges to our Vertex (from another Vertex)
	for (it = graphMap.begin(); it != graphMap.end(); it++)
	{
		if (it->second.targetExist(temp))
			it->second.removeEdge(Edge(temp));
	}

	graphMap.erase(v);			//erases that Vertex from the map

	return true;
}


//function adds an edge to the graph
bool Graph::addEdgeShell(string s, string t)
{
	if (!vertexExist(s) || !vertexExist(t))		//check if source and target vertices exist
		return false;

	if (graphMap[s].edgeExist(t))				//check if edge already exist
		return false;

	graphMap[s].addEdge(&graphMap[t]);			//add the edge

	return true;
}


//function deletes an edge from the graph
bool Graph::delEdgeShell(string s, string t)
{
	if (!vertexExist(s) || !vertexExist(t))		//check if source and target vertices exist
		return false;

	if (!graphMap[s].edgeExist(t))				//check if edge exist
		return false;

	graphMap[s].removeEdge(Edge(&graphMap[t]));	//delete the edge

	return true;
}


//given Vertex v, prints all vertices u that have an edge from v to u
bool Graph::printNeighborsShell(string k)
{
	if (!vertexExist(k))
		return false;

	list<Edge>::iterator it;

	for (it = graphMap[k].EdgeList.begin(); it != graphMap[k].EdgeList.end(); it++)
		cout << it->target->Key << " ";

	return true;
}


//given Vertex v, prints all vertices u that have an edge from u to v
bool Graph::printFollowersShell(string k)
{
	if (!vertexExist(k))
	{
		cout << "ERROR" << endl;
		return false;
	}

	//go through map (outer loop) and for each Vertex check if it has an edge to our Vertex (inner loop)
	//if it does, print the key
	map<string, Vertex>::iterator it;

	for (it = graphMap.begin(); it != graphMap.end(); it++)
	{
		list<Edge>::iterator jt;

		for (jt = it->second.EdgeList.begin(); jt != it->second.EdgeList.end(); jt++)
			if (jt->target->Key == k)
				cout << it->first << " ";
	}

	return true;
}


//Print from Vertex with key that matches given string using BFS (Breadth First Search)
void Graph::printAllReachedShell(string k)
{
	if (!vertexExist(k))
	{
		cout << "ERROR" << endl;
		return;
	}

	//set all visited flags to false;
	for (map<string, Vertex>::iterator it = graphMap.begin(); it != graphMap.end(); it++)
		it->second.visited = false;

	list<Vertex> que;

	graphMap[k].visited = true;				//set root Vertex to visited (true)

	que.push_back(graphMap[k]);

	while (!que.empty())
	{
		cout << que.front().Key << " ";

		list<Edge> listCopy = que.front().EdgeList;

		que.pop_front();

		for (list<Edge>::iterator it = listCopy.begin(); it != listCopy.end(); it++)
		{
			if (!it->target->visited)
			{
				it->target->visited = true;
				que.push_back(*(it->target));
			}
		}
	}
}//Print complete Graph
bool Graph::printAll()
{
	map<string, Vertex>::iterator it;

	//Run through Graph and print each Vertex and it's edges (using print())
	for (it = graphMap.begin(); it != graphMap.end(); it++)
	{
		it->second.print();
		cout << endl;
	}

	return true;
}