#include <iostream>
#include <climits>
#include <vector>
#include <list>
#include <queue>
#include <utility>
using namespace std;
using iPair = pair<int, int>;

class Graph{
    public:
        int V;
        list<iPair> *adjacency;
        Graph(int v);
        void addEdge(int u, int v, int w);
        void PrimMST();
};

Graph::Graph(int v = 0){
    V = v;
    adjacency = new list<iPair>[V];
}

void Graph::addEdge(int u, int v, int w){
    adjacency[u].push_back({v, w});
    adjacency[v].push_back({u, w});
}

void Graph::PrimMST(){
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    int source = 0;

    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    pq.push({0, source});
    dist[source] = 0;

    while (!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;
        for (auto it = adjacency[u].begin(); it != adjacency[u].end(); it++){
            int v = it->first;
            int weight = it->second;
            if (!inMST[v] && dist[v] > weight){
                dist[v] = weight;
                pq.push({dist[v], v});
                parent[v] = u;
            }
        }
    }
    for (int i=1; i<V; i++){
        cout << "(" << parent[i] << ", " << i << ")\n";
    }
}

int main(){
    Graph g(10);
    g.addEdge(0, 1, 20);
    g.addEdge(0, 2, 4);
    g.addEdge(2, 1, 6);
    g.addEdge(2, 3, 35);
    g.addEdge(3, 5, 40);
    g.addEdge(4, 5, 69);
    g.PrimMST();
    // cout << "Hello";
    return 0;
}