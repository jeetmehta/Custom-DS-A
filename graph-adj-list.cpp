#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class Graph {
	private:
		int V;
		list <int> *adj_list;
	public:
		Graph(int numNodes);
		void addEdge(int nodeA, int nodeB);
		void printGraph();
}

Graph::Graph(int numNodes)
{
	V = numNodes;
	adj_list = new list<int>[V];
}

void Graph::addEdge(int nodeA, int nodeB)
{
	adj_list[nodeA].push_back(nodeB);
	adj_list[nodeB].push_back(nodeA);
}

void Graph::printGraph()
{
	for (int i = 0; i < V; i++)
	{
		cout << "Node " << i << ": ";
		list<int>::iterator ptr = adj_list[i].begin();
		while (ptr != adj_list[i].end())
		{
			cout << "-> " << adj_list[i].at(ptr) << " ";
			ptr++;
		}
	}
}
