#include "GraphElements.h"

Edge::Edge(Vertex* t)
{
	target = t;
}

bool Edge:: operator==(const Edge& e) const
{
	if (this->target != e.target)
		return false;

	return true;
}

Vertex::Vertex(string key)
{
	Key = key;
	reached = false;
	//color = White;
}

void Vertex::addEdge(Edge e)
{
	EdgeList.push_back(e);
}

bool Vertex::removeEdge(Edge e)
{
	EdgeList.remove(e);

	return true;
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

bool Vertex::edgeExist(string s)
{
	list<Edge>::iterator it;

	for (it = EdgeList.begin(); it != EdgeList.end(); it++)
	{
		if (it->target->Key == s)
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

void Vertex::print()
{
	cout << Key << ": ";

	//list<Edge>::iterator it;

	for (list<Edge>::iterator it = EdgeList.begin(); it != EdgeList.end(); it++)
	{
		cout << it->target->Key << " ";
	}
}