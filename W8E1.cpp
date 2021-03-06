#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <list>
#include <functional>

# define INF 0x3f3f3f3f // infinity
std::ofstream f("Dijkstras.txt");

typedef std::pair<int, int>Pair; // A Pair of integers

class Graph {
	int V; // Number of vertices
	std::list< std::pair<int,int>>*adj; // alocate memory for An adj list

public:
	Graph(int V) {  //Constructor
		this->V = V;
		adj = new std::list<Pair>[V];
	}
	void addEdge(int u, int v, int w) {  // u- vertex, v - neighbours , w - cost

		adj[u].push_back(std::make_pair(v, w));
		adj[v].push_back(std::make_pair(u, w));  //push the values into the adj list
	}
	void Dijkstrats(int);
};

void Graph::Dijkstrats(int shortpath) 
{
	/*Create a priority quene*/
	std::priority_queue< Pair, std::vector <Pair>, std::greater<Pair> > Priority_QUEUE;

	std::vector<int> Dist(V, INF);
	Priority_QUEUE.push(std::make_pair(0, shortpath));
	Dist[shortpath] = 0;

	while (!Priority_QUEUE.empty())
	{

		int u = Priority_QUEUE.top().second;
		Priority_QUEUE.pop();

		std::list< std::pair<int, int> >::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{

			int v = (*i).first;
			int weight = (*i).second;

			if (Dist[v] > Dist[u] + weight)
			{

				Dist[v] = Dist[u] + weight;
				Priority_QUEUE.push(std:: make_pair(Dist[v], v));
			}
		}
	}

	for (int i = 0; i < V; ++i)
		f << "vertex -> " << i << " Distance-> "<< Dist[i] << "\n";
}

int main()
{

	Graph graph(6);   // 6- means the number of vertices in the graph
	graph.addEdge(0, 1, 2); graph.addEdge(2, 3, 1);
	graph.addEdge(1, 0, 2); graph.addEdge(3, 2, 1);
	graph.addEdge(0, 4, 5); graph.addEdge(3, 4, 2);
	graph.addEdge(4, 0, 5); graph.addEdge(4, 3, 2);
	graph.addEdge(2, 4, 3); graph.addEdge(4, 5, 4);
	graph.addEdge(4, 2, 3); graph.addEdge(5, 4, 4);
	int startingpoint;
	std::cout << "Choose a starting point for the graph from 0 to 5: "; std::cin >> startingpoint;
	std::cout << "Now check the Dijkstrats.txt file for your result!";
	f << "Show me the total cost from "<<startingpoint << " to all vertices\n";
	graph.Dijkstrats(startingpoint);
	return 0;
}
