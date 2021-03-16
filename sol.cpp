#include <bits/stdc++.h>
#include "GraphTemplate.h"

using namespace std;

int main() {
	int ch;
	Graph <int> g(8);
	cout << "Graph Operations" << endl;
	cout << "[1] Adjacency List" << endl;
	cout << "[2] Adjacency Matrix" << endl;
	cout << "Enter choice: ";
	cin >> ch;
	if (ch == 1) {
		g.AddEdge(0, 6);
		g.AddEdge(1, 5);
		g.AddEdge(2, 0);
		g.AddEdge(2, 4);
		g.AddEdge(3, 5);
		g.AddEdge(4, 1);
		g.AddEdge(4, 3);
		g.AddEdge(5, 7);
		g.AddEdge(6, 1);
		g.AddEdge(6, 7);
		g.PrintGraph();
		cout << endl << "DFS Traversal..." << endl;
		g.DFS(1);
		cout << endl;
		cout << endl << "BFS Traversal..." << endl;
		g.BFS(3);
	} else if (ch == 2) {
		g.AddEdge2(0, 1);
		g.AddEdge2(0, 4);
		g.AddEdge2(1, 2);
		g.AddEdge2(1, 0);
		g.AddEdge2(1, 3);
		g.AddEdge2(1, 4);
		g.AddEdge2(2, 1);
		g.AddEdge2(2, 3);
		g.AddEdge2(3, 1);
		g.AddEdge2(3, 2);
		g.AddEdge2(3, 4);
		g.AddEdge2(4, 0);
		g.AddEdge2(4, 1);
		g.AddEdge2(4, 3);
		g.PrintGraph2();
	}
	cout << endl << endl;
	return 0;
}
