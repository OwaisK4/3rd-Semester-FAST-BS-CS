#include <iostream>
using namespace std;

template <typename T>
class Node{
    public:
        int data;
        Node* next;
        Node* prev;
        Node(){
            data = 0;
            next = NULL;
            prev = NULL;
        }
        Node(int d){
            data = d;
            next = NULL;
            prev = NULL;
        }
};

template <typename T>
class DoublyLinkedList{
    public:
        Node<T>* head;
        DoublyLinkedList(){
            head = NULL;
        }
        void insert(T d){
            Node<T>* newNode = new Node<T>(d);
            if (head == NULL){
                head = newNode;
            }
            else{
                Node<T>* temp;
                for (temp = head; temp->next != NULL; temp = temp->next);
                temp->next = newNode;
                newNode->prev = temp;
            }
        }
        void printList(){
            Node<T>* temp;
            for (temp = head; temp != NULL; temp = temp->next){
                cout << temp->data << " ";
            }
            cout << "\n";
        }
};

template <typename T>
class Graph{
    public:
        int V;
        DoublyLinkedList<T>* list;
        Graph(){
            V = 0;
            list = new DoublyLinkedList<T>[V];
        }
        Graph(int vertices){
            V = vertices;
            list = new DoublyLinkedList<T>[V];
        }
        void addEdge(int x, int y){
            if (x >= V || y >= V){
                cout << "Vertex does not exist in graph.\n";
                return;
            }
            list[x].insert(y);
            list[y].insert(x);
        }
        void printEdges(){
            for (int i=0; i<V; i++){
                cout << "Vertex " << i << " :\t";
                list[i].printList();
            }
        }
};

int main(){
    Graph<int> graph(10);
    int x, y;
    while (true){
        cout << "Enter -1 to cancel: " << endl;
        cout << "Enter the position of first edge: ";
        cin >> x;
        if(x == -1){
            break;
        }
        cout << "Enter the position of linked edge: ";
        cin >> y;
        graph.addEdge(x, y);
    }
    cout << "\nAdjacency list:\n";
    graph.printEdges();
    return 0;
}