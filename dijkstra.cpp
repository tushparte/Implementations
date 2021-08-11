#include <bits/stdc++.h>

using namespace std;

#define present(container, element) (container.find(element) != container.end())
#define cpresent(container, element) (find(all(container), element) != container.end())
#define INF 0x3f3f3f3f
#define f(n) for (int i = 0; i < n; i++)
typedef pair<int, int> iPair;
const double epsilon = 1e-7;

class Graph
{
    int v;
    list<iPair> *adj;

public:
    Graph(int v);
    void addEdge(int u, int v, int w);
    void shortestPath(int s);
};

Graph::Graph(int v)
{
    this->v = v;
    adj = new list<iPair>[v];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::shortestPath(int s)
{
    priority_queue<iPair, vector<iPair>, greater<iPair> > pq;
    pq.push(make_pair(0, s));
    vector<int> dist(v, INF);
    dist[s] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        list<iPair>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); i++)
        {
            int v = (*i).first;
            int w = (*i).second;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < v; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V = 9;
    Graph g(V);

    //  making above shown graph
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

    g.shortestPath(0);

    return 0;
}