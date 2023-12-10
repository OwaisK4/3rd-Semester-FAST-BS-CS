#include<iostream>
#include <list>
#include <stack>
using namespace std;
 
// Class to represent a graph
class Graph{
    private:
        int V;
        list<int> *adj;
    public:
        Graph(int V){
            this->V = V;
            adj = new list<int>[V];
        }
        void addEdge(int v, int w){
            adj[v].push_back(w);
        }
        void topologicalSort(){
            stack<int> Stack;
            stack<int> s;
            bool *visited = new bool[V];
            for (int i = 0; i < V; i++)
                visited[i] = false;
            
            for (int i=0; i<V; i++){
                if (!visited[i]){
                    visited[i] = true;
                    s.push(i);
                    while (!s.empty()){
                        int x = s.top();
                        s.pop();
                        for (auto it : adj[x]){
                            if (!visited[it]){
                                visited[it] = true;
                                s.push(it);
                            }
                        }
                        Stack.push(x);
                    }
                }
            }
            while (!Stack.empty()){
                cout << Stack.top() << " ";
                Stack.pop();
            }
        }
};

int main(){
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
 
    cout << "Following is a Topological Sort of the given graph \n";
    g.topologicalSort();
 
    return 0;
}