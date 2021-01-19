#include "GraphElements.h"

Edge::Edge(Vertex* t)
{
	//eli levin, can you see this message?
	target = t;
}

bool Edge:: operator==(Edge& e)
{
	if (this->target != e.target)
		return false;

	return true;
}

Vertex::Vertex(string key)
{
	Key = key;
	color = Color::White;
}

void Vertex::addEdge(Edge e)
{
	EdgeList.push_back(e);
}

int Vertex::numOfNeighbors()
{
	return EdgeList.size();
}

bool Vertex::targetExist(Vertex* v)
{
	list<Edge>::iterator it;

	for (it = EdgeList.begin(); it != EdgeList.end(); it++)
	{
		if (*v == *(it->target))
			return true;
	}

	return false;
}

bool Vertex:: operator==(Vertex& v)
{
	if (this->Key == v.Key)
		return true;

	return false;
}