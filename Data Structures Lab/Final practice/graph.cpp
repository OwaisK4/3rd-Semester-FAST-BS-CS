#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Edge{
	public:
		int destid;
//		string destname;
		int weight;
		
		Edge(){
			destid = 0;
			weight = 0;
		}
		Edge(int id ,int w){
			destid = id;
			weight = w;
		}
		int getdestid(){
			return destid;
		}
		int getweight(){
			return weight;
		}
};
class Vertex{
	public:
		int sourid;
		string vertexname;
		list <Edge> edgelist;
		
		Vertex(){
			sourid = 0;
			vertexname = "";
		}
		Vertex(int id,string name){
			sourid = id;
			vertexname = name;
		}
		int getsourid(){
			return sourid;
		}
		string getvertexname(){
			return vertexname;
		}
		void displayedgelist(){
			for(auto i = edgelist.begin(); i != edgelist.end() ; i++){
				cout << "[" <<i->getdestid() <<", "<<i->getweight()<<"] -->";
			}
		}
};
class Graph{
	public:
		vector <Vertex> vertices;
		
		void addvertex(int id ,string name){
			Vertex v(id,name);
			vertices.push_back(v);
		}
		void printvertex(){
			for(auto i : vertices){
				Vertex v = i;
				cout<<v.getsourid()<<"  "<<v.getvertexname()<<endl;
			}
		}
		bool checkvertexexist(int id){
			for(auto i : vertices ){
				Vertex v = i;
				if(v.sourid == id){
					return true;
				}
			}
			return false;
		}
		void addedge(int sid,int did,int weight ){
			bool check1 = checkvertexexist(sid);
			bool check2 = checkvertexexist(did);
			
			if(check1 && check2 == true){
				Edge e(did,weight);
				Edge e2(sid,weight);

				for(auto& i : vertices){
					// Vertex v = i ;
					if(i.getsourid() == sid){
						i.edgelist.push_back(e);
					}
					else if(i.getsourid() == did){
						i.edgelist.push_back(e2);
					}
				}
				/*
				for(int i =0 ;i < vertices.size();i++){
					if(vertices.at(i).getsourid() == sid){
						vertices.at(i).edgelist.push_back(e);
					}
					else if(vertices.at(i).getsourid() == did){
						vertices.at(i).edgelist.push_back(e2);
					}
				}
				*/
			}
		}
		void displaygraph(){
			for(auto i : vertices){
				cout<<endl<<"\n["<<i.getsourid()<<", "<<i.getvertexname()<<"]-->";
				for(auto j : i.edgelist){
					cout<<"["<<j.destid<<", "<<j.getweight()<<"] -->";
				} 
//				v.displayedgelist();
			}
		}
};
int main(){
	Graph g;
	g.addvertex(1,"fast");
	g.addvertex(2,"hadeed");
	g.addvertex(3,"north");
	g.addvertex(4,"johar");
	
	g.printvertex();
	if(g.checkvertexexist(1)){
		cout<<"\nvertex exist";
	}
	else{
		cout<<"\nvertex does not exist";
	}
	if(g.checkvertexexist(5)){
		cout<<"\nvertex exist";
	}
	else{
		cout<<"\nvertex does not exist";
	}
	
	g.addedge(1,2,100);
	g.addedge(3,4,200);
	g.displaygraph();
}