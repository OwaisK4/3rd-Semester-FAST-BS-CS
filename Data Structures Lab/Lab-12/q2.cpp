#include <iostream>
#include <vector>
using namespace std;
template <class T>
class Node{
    public:
        T data;
        Node *next,*prev;
        Node(T d){
            data = d;
            next = prev = NULL;
        }
};
template<class T>
class DoublyLinkedList{
    public:
        Node<T> *head;
        DoublyLinkedList(){
            head = NULL;
        }
        void insert(T data){
            if(head == NULL){
                head = new Node<T>(data);
                return;
            }
            Node<T>* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            Node<T>* newNode = new Node<T>(data);
            temp->next = newNode;
            newNode->prev = temp;
        }
        void printList(){
            Node<T>* temp = head;
            while(temp!= NULL){
                cout<<temp->data + 1<< "  ";
                temp = temp->next;
            }
            cout<<endl;
        }
};
template<class T>
class Graph{
    private:
        DoublyLinkedList<T>* graphNodes;
        int nodeCount;
        vector<int> *adjacencyList;
        void createGraph(){
            for(int i=0;i<nodeCount;i++){
                for(int j=0;j<adjacencyList[i].size();j++){
                        graphNodes[i].insert(j);
                }
            }
        }
    public:
        Graph(int nodeCount){
            this->nodeCount = nodeCount;
            adjacencyList = new vector<int>[nodeCount];
            graphNodes = new DoublyLinkedList<T>[nodeCount];
        }
        void emptyAdjacencyList(){
            for(int i=0;i<nodeCount;i++){
                for(int j=0;j<nodeCount;j++){
                    adjacencyList[i].push_back(0);
                }
            }
        }
        void inputAdjacencyList(){
            int friend1;
            int friend2;
            while(true){
                cout<<"Enter -999 to cancel: "<<endl;
                cout<<"Enter the position of first edge: ";
                cin>>friend1;
                if(friend1 == -999){
                    break;
                }
                cout<<"Enter the position of linked edge: ";
                cin>>friend2;
                adjacencyList[friend1].push_back(friend2);
            }
            createGraph();
        }
        void printAdjacencyList(){
            for(int i=0;i<nodeCount;i++){
                for(int j=0;j<adjacencyList[i].size();j++){
                    cout<<adjacencyList[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        void printGraph(){
            for(int i=0;i<nodeCount;i++){
                cout<<i+1<< " --> ";
                graphNodes[i].printList();
            }
        }
};
 
int main(){
    int n;
    cout<<"Enter the number of edges: ";
    cin>>n;
    Graph<int> G(n);
    G.inputAdjacencyList();
    G.printAdjacencyList();
    G.printGraph();
}