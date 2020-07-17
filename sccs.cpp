#include <bits/stdc++.h>

using namespace std;

/*
  Kosaraju's two-pass algorithm
  1. Run DFS on G to compute finishing times of nodes
  2. Run DFS on G' in the reverse order of finishing times to print
  strongly connected components. (G' is graph with edges reversed.)
*/

class Graph {
	int V; // No. of vertices
	list<int> *adj;
  stack<int> finishTimes();
  void fill(int start, vector<bool>& visited, stack<int>& s);
  void dfs(int start, vector<bool>& visited);
public:
	Graph(int V); // Constructor
	void addEdge(int u, int v);
  Graph getReversedGraph();
  void printGraph();
  void SCCS();
};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<int> [V];
}

void Graph::addEdge(int u, int v) {
	adj[u].push_back(v);
}

Graph Graph::getReversedGraph() {
  Graph rgraph(V);

  for (int i = 0; i < V; ++i) {
    for (auto node: adj[i])
      rgraph.addEdge(node, i);
  }

  return rgraph;
}

void Graph::printGraph() {
  for (int i = 0; i < V; ++i) {
    cout << i << " : " ;
    for (auto node: adj[i])
      cout << node << " ";
    cout << endl;
  }
}

void Graph::dfs(int start, vector<bool>& visited) {
  visited[start] = true;
  cout << start << " ";
  for (auto node: adj[start]) {
    if (!visited[node])
      dfs(node, visited);
  }
}

void Graph::fill(int start, vector<bool>& visited, stack<int>& s) {
  visited[start] = true;
  for (auto node: adj[start])
    if (!visited[node])
      fill(node, visited, s);
  s.push(start);
}

stack<int> Graph::finishTimes() {
  vector<bool> visited(V, false);
  stack<int> s;
  for (int i = 0; i < V; ++i)
    if (!visited[i])
      fill(i, visited, s);
  return s;
}

void Graph::SCCS() {
  // get reversed Graph G'
  Graph rgraph = getReversedGraph();
  // compute finishing times in (last to first)
  stack<int> s = finishTimes();
  vector<bool> visited(V, false);
  // run DFS for each unvisited node for G'
  while (!s.empty()) {
    int v = s.top();
    s.pop();
    if (!visited[v]) {
      rgraph.dfs(v, visited);
      cout << endl;
    }
  }
}

int main() {
  Graph g(5);
  g.addEdge(1, 0);
  g.addEdge(0, 2);
  g.addEdge(2, 1);
  g.addEdge(0, 3);
  g.addEdge(3, 4);
  g.SCCS();
	return 0;
}
