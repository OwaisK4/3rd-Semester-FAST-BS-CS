#include <iostream>
#include <list>
#include <stack>
using namespace std;
using iPair = pair<int,int>;

class Graph{
	public:
		int V;
		list<int> *l1;
	Graph(){
		V=0;
		l1=new list<int>[V];
	}

	Graph(int v){
		this->V=v;
		l1=new list<int>[V];
	}

	void AddEdge(int x,int y){
	   l1[x].push_back(y);
	   l1[y].push_back(x);
	}

	void PrintEdge(){
		for(int i=0;i<V;i++)
		{
			cout<<"Vertices "<<i<<": ";
			for(int nbr: l1[i])
			{
				cout<<" "<<nbr<<",";
			}
			cout<<endl;
		}
	}

	void DFS(int s){
		bool *visited=new bool[V];
		for(int i=0;i<V;i++)
		{
			visited[i]=false;
		}
		stack<int> st;
		visited[s]=true;
		st.push(s);
		list<int>::iterator i;
		
		while(!st.empty())
		{
			s=st.top();
			cout<<" "<<s;
			st.pop();
			for(i=l1[s].begin();i!=l1[s].end();++i)
			{
				if(!visited[*i])
				{
					visited[*i]=true;
					st.push(*i);
				}
			}
		}
	}
};

int main(){
	Graph g(5);
	g.AddEdge(0,1);
	g.AddEdge(0,4);
	g.AddEdge(0,2);

	g.AddEdge(1,0);
    g.AddEdge(1,2);
	
    g.AddEdge(2,0);
    g.AddEdge(2,1);
    g.AddEdge(2,4);
    g.AddEdge(2,3);
	g.AddEdge(2,3);

    g.AddEdge(3,2);
    g.AddEdge(3,4);

    g.AddEdge(4,0);
    g.AddEdge(4,2);
    g.AddEdge(4,3);
	cout<<"Neighbours of each Vertex: "<<endl<<endl<<endl;
	g.PrintEdge();
    
    int start;
	cout<<endl<<"Depth First Search: ";
	cout<<"Enter Vertex from where to start: "; 
    cin>>start;
	g.DFS(start);
 
}
