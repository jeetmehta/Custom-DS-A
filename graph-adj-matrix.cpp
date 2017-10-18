#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
	private:
		vector <vector <int>> graph;
		int n;
	public:
		Graph(int n);
		vector <int> getEdgesForNode(int node);
		void addEdge(int nodeA, int nodeB);
		void printGraph();

};

Graph::Graph(int n)
{
	vector <vector <int>> grid(n, vector <int>(n, -1));
	graph = grid;
	ZZn = n;
}

void Graph::addEdge(int nodeA, int nodeB)
{
	if ((nodeA < 0 || nodeA >= n) || (nodeB < 0 || nodeB >= n))
		return;

	graph[nodeA - 1][nodeB - 1] = 1;
	graph[nodeB - 1][nodeA - 1] = 1;
	return;
}

vector <int> Graph::getEdgesForNode(int node)
{
	if (node < 0 || node >= n)
		return {};
	return graph[node - 1];
}

void Graph::printGraph()
{
	for (int i = 0; i < graph.size(); i++)
	{
		for (int j = 0; j < graph[i].size(); j++)
		{
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	Graph* graphTest = new Graph(3);

	graphTest->addEdge(1,2);
	graphTest->addEdge(2,3);

	graphTest->printGraph();
	
	return 0;
}