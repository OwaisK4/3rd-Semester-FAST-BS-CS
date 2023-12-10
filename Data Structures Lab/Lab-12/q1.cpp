#include <iostream>
#include <list>
using namespace std;
typedef pair<int,int> Pair;

class Graph{
	public:
		int V;
		list<int> *L;

	Graph(){
		V=0;
		L=new list<int>[V];
	}

	Graph(int v){
		V=v;
		L=new list<int>[V];
	}
    
	void AddEdge(int x,int y){
	   L[x].push_back(y);
	   L[y].push_back(x);
	}
    
	void PrintEdge(){
		for(int i=0;i<V;i++){
			cout<<"Vertices "<<i<<": ";
			for(int j: L[i]){
				cout<<" "<<j<<",";
			}
			cout<<endl;
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
	cout << "Neighbours of each Vertex: "<<endl<<endl;
	g.PrintEdge();
	cout << endl;
}