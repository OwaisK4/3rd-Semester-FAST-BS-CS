#include <iostream>
#include<queue>
#include<stack>
#include<list>

using namespace std;

class Graph
{
	int v; // no of vertices
	list<int> *adj; // Pointer to an array containing adjacency lists
public:
	Graph(int);
	void addEdge(int , int);
	void BFS(int);
	void DFS(int);
};

Graph :: Graph(int vertices)
{
	v = vertices;
	adj = new list<int>[v];
}

void Graph :: addEdge(int v, int w)
{
	adj[v].push_back(w); // add w to v's list
}

void Graph :: BFS(int s)
{
	bool *visited = new bool[v];
	for(int i=0; i<v; i++)
		visited[i] = false;
	
	queue<int> q;

	// mark current node as visited and enque it
	visited[s] = true;
	q.push(s);

	list<int> :: iterator i;

	while(!q.empty())
	{	
		s = q.front();
		cout<<s<<" ";
		q.pop();
		// Get all adjacent vertices of the dequeued
		// vertex s. If a adjacent has not been visited, 
		// then mark it visited and enqueue it
		for(i = adj[s].begin(); i!=adj[s].end();i++ )
		{
			//cout<<"i: "<<*i<<endl;
			if(!visited[*i])
			{
				visited[*i] = true;
				q.push(*i);
			}
		}

	}
}

void Graph :: DFS(int n)
{
	bool *visited = new bool[v];
	for(int i=0; i<v; i++)
		visited[i] = false;

	stack<int> s;
	// mark current node as visited and push it on stack
	visited[n] = true;
	s.push(n);

	list <int> :: iterator i;

	while(!s.empty())
	{
		n = s.top();
		cout<<n<<" ";
		s.pop();
		for(i=adj[n].begin(); i!=adj[n].end();i++)
		{
			if(!visited[*i])
			{
				visited[*i] = true;
				s.push(*i);
			}

		}
	}
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
    cout<<endl;

    cout << "Following is Depth First Traversal "
         << "(starting from vertex 2) \n";
    g.DFS(2);
    cout<<endl;
 
    return 0;
}
