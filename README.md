# Homework5-Graphs
These programs have been designed to comply with the homework instructions. Certain ways of writing the program is not always based on my preference but based on the homework requirements.

Homework Instructions:

Exercise 5: Graphs
In this exercise, we would like to implement a system for making follow-up recommendations to
members of a discussion forum.
For this purpose, we will have a map for a string representing some writer X to a list of all the
writers that X follows (receives messages from).
Objective: It will be possible to give each writer the list of writers who follow him, and so it will
also be possible to give him recommendations for additional writers that he can follow.
Step A: Define the graph
We will define a class for a directed graph where each vertex in the graph contains a key of type
string.
• Define a class Vertex, which contains a key (string type), which represents a member’s
name, a linked list of edges of other writers that s/he follows, and other details as needed.
• Define a class Edge, which contains pointers to the source and target vertices.
• Comment: Since there may be a cycle in these class definitions (a vertex uses an edge and an
edge uses a vertex), you may need to declare the edge class before the definition of the
vertex class.
For example, this is an illustration for what your classes for vertices and edges may look like.
class Vertex;
class Edge//this class represent a edge includes:two vertexes
{
public:
Vertex* destination;
public:
Edge(Vertex* destination);
bool operator==(Edge & v);
};
//this class represents a vertex includes:key ,list of his edges
enum Color {White,Gray,Black};
class Vertex
{
string Key;
Color color;
list<Edge> EdgeList;
public:
Vertex(string key);
void adde(Edge);
int numOfNeighbours();
bool destinationExists(Vertex* v);
void print();
friend class Graph;
};
Define a class for a directed graph that will store all the vertices in the graph:
The graph will be implemented using a map of vertices, with each vertex having its own list of
neighbors.
The following methods must be defined for the graph:
• constructor: (initializes the graph to a graph).
• destructor
• Add a vertex to the graph.
• Delete a vertex and all edges that are incident (to or from) it.
• Add an edge to the graph (make sure you do not add an edge that already exists).
• Delete an edge.
• Given vertex v, print all vertices u that have an edge from v to u.
• Given vertex v, print all the vertices u that have an edge from u to v.
• Given vertex v, prints all vertices that are reachable from v.
• Print the entire graph.
• Additional methods as needed.
It is recommended that you check the previous implementation before moving on to the next part.
Part B: Implementing a system of message followers :
Write a main program that creates a graph for members of the discussion forum which allows the
following steps to be performed: (It is recommended you use the program posted in moodle).
A. Add a new writer to the discussion forum graph
B. Delete a writer - Including deleting all edges that are incident to and from the writer
C. Create an edge from X to Y to signify that writer X follows writer Y.
D. Delete an edge from X to Y to signify that writer X no longer follows writer Y .
E. Given writer X, print all the writers that X follows .
F. Given writer X, print all the writers that follow X.
G. Given writer X, print all the writers that have a path from X to them.
H. Print the entire discussion forum.
I. Exit the system
Good Luck!
