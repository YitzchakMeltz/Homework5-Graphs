#include "Graph.h"

Vertex* Graph::findVertex(string s)
{
	map<Vertex, list<Vertex>>::iterator it;

	for (it = graphMap.begin(); it != graphMap.end(); it++)
	{
		if (it->first.Key == s)
			return it;
	}

	return NULL;
}

bool Graph::addVertexShell(string v)
{
	Vertex tempV = Vertex(v);
	list<Vertex> tempN;
	graphMap.insert(pair<Vertex, list<Vertex>>(tempV, tempN));
}

bool Graph::delVertexShell(string v)
{


	// delete edges that are incident (to or from ) it

	list<Vertex>::iterator it;

	for(it=)

}

bool Graph::printAll()
{
	map<Vertex, list<Vertex>>::iterator it;

	for (it = graphMap.begin(); it != graphMap.end(); it++)
	{
		it->first.print();
	}

	return true;
}