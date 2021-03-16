#ifndef GRAPH_H
#define GRAPH_H
#include <bits/stdc++.h>

using namespace std;

template <class T>
class Graph {
	private:
		T V;
		list<T>  *adj;
		T ** adj2;
		void DFSUtil(T v, bool visited[]);
		void BFSUtil(T s, bool visited[]);
	public:
		Graph(T);
		void AddEdge(T u, T v);
		void AddEdge2(T u, T v);
		void PrintGraph();
		void PrintGraph2();
		void DFS(T v);
		void BFS(T s);
};

template <class T>
Graph<T>::Graph(T x) {
	V = x;
	adj = new list <T> [V];
	adj2 = new T* [V];
	for (int i = 0; i < V; i++) {
		adj2[i] = new T[V];
	}
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			adj2[i][j] = 0;
		}
	}
}

template <class T>
void Graph<T>::AddEdge(T u, T v) {
	adj[u].push_back(v);
}

template <class T>
void Graph<T>::AddEdge2(T u, T v) {
	adj2[u][v] = 1;
}

template <class T>
void Graph<T>::PrintGraph() {
	cout << "Adjacency List..." << '\n';
	for (int v = 0; v < V; v++) {
		cout << "V[" << v << "]";
		for (auto x : adj[v]) {
			cout << " -> " << x;
		}
		cout << '\n';
	}
}

template <class T>
void Graph<T>::PrintGraph2() {
	cout << "Adjacency Matrix..." << '\n' << '\n';
	cout << '\t';
	for (int i = 0; i < V; i++) {
		cout << "V[" << i << "]" << '\t';
	}
	cout << '\n';
	for (int i = 0; i < V; i++) {
		cout << "V[" << i << "]" << '\t';
		for (int j = 0; j < V; j++) {
			cout << adj2[i][j] << '\t';
		}
		cout << '\n';
	}
	cout << '\n';
}

template <class T>
void Graph<T>::DFSUtil(T v, bool visited[]) {
	visited[v] = true;
	cout << v << " ";
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); i++) {
		if (!visited[*i]) {
			DFSUtil(*i, visited);
		}
	}
}

template <class T>
void Graph<T>::DFS(T v) {
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}
	DFSUtil(v, visited);
	for (int i = 0; i < V; i++) {
		if (!visited[i]) {
			DFSUtil(i, visited);
		}
	}
	for (int i = 0; i < V; i++) {
		if (!visited[i]) {
			cout << i << " ";
		}
	}
}

template <class T>
void Graph<T>::BFS(T s) {
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}
	BFSUtil(s, visited);
	for (int i = 0; i < V; i++) {
		if (!visited[i]) {
			BFSUtil(i, visited);
		}
	}
	for (int i = 0; i < V; i++) {
		if (!visited[i]) {
			cout << i << " ";
		}
	}
}

template <class T>
void Graph<T>::BFSUtil(T s, bool visited[]) {
	list<T> queue;
	visited[s] = true;
	queue.push_back(s);
	list<int>::iterator i;
	while (!queue.empty()) {
		s = queue.front();
		cout << s << " ";
		queue.pop_front();
		for (i = adj[s].begin(); i != adj[s].end(); i++) {
			if (!visited[*i]) {
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}

#endif
