#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <list>

std::ofstream f("BFS.txt");


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
	void BFS(int);
};

void Graph::BFS(int start) {
	bool *visited = new bool[V];   
	for (int i = 0; i <= V - 1; ++i) {
		visited[i] = false;
	}
	
	std::list<int> queue;
	std::list<int>::iterator i; // i to iterate through the list
	
	visited[start] = true; // starting point is already visited
	queue.push_back(start);

	while (!queue.empty())
	{
		start = queue.front();
		f << start << " "; //print the vertex in the file and de-queue it
		queue.pop_front();

		for (i = adj[start].begin(); i != adj[start].end(); ++i) 
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
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
	int answer;
	std::cout << "Choose a starting point for the graph from 0 to 5: "; std::cin>> answer;
	std::cout << "Now check the BFS.txt file for your result!";
	f << "BFS (Breadth First Traversal) starting with vertex " << answer << "\n";
	graph.BFS(answer);
	return 0;
}
