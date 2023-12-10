#include <iostream>
#include <list>
#include <queue>
#include <stack>
using namespace std;

class Graph{
    public:
        int V;       // Vertices
        list<int> *adjacency;
        
        Graph(int v = 0){
            V = v;
            adjacency = new list<int>[V];
        }

        void addEdge(int fromVertex, int toVertex){
            adjacency[fromVertex].push_back(toVertex);
            adjacency[toVertex].push_back(fromVertex);
        }

        void BFS(int start){
            bool *visited = new bool[V] {0};
            queue<int> q;
            
            visited[start] = true;
            q.push(start);
            while (!q.empty()){
                start = q.front();
                cout << start << " ";
                q.pop();
                for (auto it : adjacency[start]){
                    if (!visited[it]){
                        visited[it] = true;
                        q.push(it);
                    }
                }
            }
            cout << "\n";
        }

        void DFS(int start){
            bool *visited = new bool[V] {0};
            stack<int> q;

            visited[start] = true;
            q.push(start);
            while (!q.empty()){
                start = q.top();
                cout << start << " ";
                q.pop();
                for (auto it : adjacency[start]){
                    if (!visited[it]){
                        visited[it] = true;
                        q.push(it);
                    }
                }
                
            }
            cout << "\n";
        }
        // void printGraph();
};

int main(){
    Graph graph(10);
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 4);
    graph.addEdge(1, 3);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.BFS(0);
    graph.DFS(0);

    return 0;
}