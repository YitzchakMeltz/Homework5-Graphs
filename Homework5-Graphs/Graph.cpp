#include "Graph.h"

//returns an iterator pointing to the map level with the intended Vertex
map<Vertex, list<Vertex>>::iterator Graph::findVertex(const string& s)
{
	for (map<Vertex, list<Vertex>>::iterator it = graphMap.begin(); it != graphMap.end(); ++it)
		if (it->first.Key == s)
			return it;

	return graphMap.end();
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