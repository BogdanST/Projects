#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <list>

std::ofstream f("IsThereAPath.txt");


class Graph {
	int V; // Number of vertices
	std::list <int>*adj; // An adj list

public:
	Graph(int V) {  //Constructor
		this->V = V;
		adj = new std::list<int>[V];
	}
	void addEdge(int v, int w) {
		adj[v].push_back(w);   // Adding connection to the Adj List
	}
	bool havePath(int,int);
};

bool Graph::havePath(int v,int w) {

	if (v == w)			//check if the starting point is actually the destination point
		return true;

	bool *visited = new bool[V];
	for (int i = 0; i <= V - 1; ++i) {
		visited[i] = false;
	}

	std::list<int> queue;
	std::list<int>::iterator i; // i to iterate through the list

	visited[v] = true; // starting point is already visited
	queue.push_back(v);

	while (!queue.empty())
	{
		v = queue.front();
		f << "[ " << v << " ]"; //print the vertex in the file and de-queue it
		queue.pop_front();

		for (i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			if (*i == w)  //check the destination, and return tre if is in the adj list
				return true;

			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
	return false;
}

int main()
{
	Graph graph(6);   // 6- means the number of vertices in the graph
	graph.addEdge(0, 1); graph.addEdge(2, 3);
	graph.addEdge(1, 0); graph.addEdge(3, 2);
	graph.addEdge(0, 4); graph.addEdge(3, 4);
	graph.addEdge(4, 0); graph.addEdge(4, 3);
	graph.addEdge(2, 4); graph.addEdge(4, 5);
	graph.addEdge(4, 2); graph.addEdge(5, 4);
	int startingpoint;
	int destination;
	std::cout << "Choose a starting point for the graph from 0 to 5: "; std::cin >> startingpoint;
	std::cout << "Check a destination point "; std::cin>> destination;
	std::cout << "Now check the BFS.txt file for your result!";
	f << "Is there any path from your starting point to the destination? \n";
	if (graph.havePath(startingpoint, destination) == true)
		f << " ->There is a path from " << startingpoint << " to " << destination << "\n";
	else
		f << " ->It looks like there is no path betwween these to points" << startingpoint << " , " << destination << "\n";
	return 0;
}
