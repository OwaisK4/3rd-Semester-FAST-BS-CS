#include <iostream>
#include <vector>
#include <climits>
#include <list>
#include <set>
#include <utility>
using namespace std;

class Graph{
    public:
        int V;
        vector<vector<pair<int, int>>> adjacency;
        Graph(int v = 0){
            V = v;
            adjacency.resize(V+1);
        }
        void addEdge(int u, int v, int w){
            adjacency[u].push_back({v, w});
            adjacency[v].push_back({u, w});
        }
        void dijkstra(int source = 0){
            vector<int> dist(V + 1, INT_MAX);
            set<pair<int, int>> s;

            dist[source] = 0;
            s.insert({0, source});

            while (!s.empty()){
                auto x = *(s.begin());
                s.erase(x);
                for (auto it : adjacency[x.second]){
                    if (dist[it.first] > (dist[x.second] + it.second)){
                        s.erase({dist[it.first], it.first});
                        dist[it.first] = dist[x.second] + it.second;
                        s.insert({dist[it.first], it.first});
                    }
                }

            }
            for (int i=0; i<V; i++){
                cout << "Vertex " << i << ": ";
                // if (dist[i] < INT_MAX){
                cout << dist[i] << "\n";
                // }
            }
        }

};

int main(){
    Graph g(5);
    g.addEdge(0, 1, 20);
    g.addEdge(0, 2, 4);
    g.addEdge(2, 1, 6);
    g.addEdge(2, 3, 35);
    g.addEdge(3, 5, 40);
    g.addEdge(4, 5, 69);
    g.dijkstra(0);
    return 0;
}