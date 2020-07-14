#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> iPair;
typedef tuple<int, int, int> tpl;

class QuickUnion {
    private:
        int *id;
        int *size;
        int root(int i) {
            while(i != id[i]) {
                // path compression
                id[i] = id[id[i]]; 
                i = id[i];
            }
            return i;
        }
    
    public:
        QuickUnion(int n) {
            id = new int[n * sizeof(int)];
            size = new int[n * sizeof(int)];
            for(int i=0 ; i<n ; i++) {
                id[i] = i;
                size[i] = 1;
            }
        }

        bool find(int p, int q) {
            return root(p) == root(q);
        }

        void unite(int p, int q) {
            int i = root(p);
            int j = root(q);
            if(size[i] < size[j]) {
                id[i] = j;
                size[j] += size[i]; 
            } else {
                id[j] = i;
                size[i] += size[j];
            }
        }
};

class Graph {
	int V; // No. of vertices
	list< pair<int, int> > *adj;

public:
	Graph(int V); // Constructor
	void addEdge(int u, int v, int w);
    void kruskal();
};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<iPair> [V];
}

void Graph::addEdge(int u, int v, int w) {
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}

void Graph::kruskal() {
    vector<tpl> edges;
    for (int i = 0; i < V; ++i) {
        for (auto [neighbor, weight]: adj[i])
            edges.emplace_back(weight, i, neighbor);
    }
    sort(edges.begin(), edges.end());

    QuickUnion* qunion = new QuickUnion(V);
    int index = 0;
    int e = 0;
    vector<tpl> result;

    while (index < edges.size()) {
        auto [cost, src, dest] = edges[index++];
        if (!qunion->find(src, dest)) {
            qunion->unite(src, dest);
            result.emplace_back(src, dest, cost);
        }
    }

    for (auto [src, dest, cost]: result) {
        cout << src << " -> " << dest << endl;
    }
}

int main() {
	int V = 9;
	Graph g(V);

	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);
    g.kruskal();
    return 0;
}
