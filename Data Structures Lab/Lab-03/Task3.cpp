#include<iostream>
using namespace std;

class Node{
    public:
        int key;
        char data;
        Node* next;

    Node(){
        key = 0;
        data = ' ';
        next = NULL;
    }

    Node(int key, char data){
        this->key = key;
        this->data = data;
    }
};

class SinglyLinkedList{
    public:
        Node* head;

    SinglyLinkedList(){
        head = NULL;
    }

    SinglyLinkedList(Node* n){head = n;}

    Node* NodeExists(int key){
        Node* temp = NULL;
        Node* ptr = head;
        
        while(ptr != NULL){
            if(ptr->key == key){
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }

    void AppendNode(Node* n){
        if(NodeExists(n->key) != NULL){
            cout << "Node with this Key " << n->key << " already exists!\n";
        }
        else{
            if(head == NULL){
                head = n;
                head->next = NULL;
            }
            else{
                Node* ptr = head;
                while(ptr->next != NULL){
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->next = NULL;
            }
        }
    }

    void UpdateNodeByKey(int key, int data){
        Node* ptr = NodeExists(key);
        if(ptr!=NULL){
            ptr->data = data;
        }
        else{
            cout << "No Node with this key " << key << " exists!\n";
        }
    }

    void PrintList() {
		if (head == NULL) {
			cout << "No Nodes in Singly Linked List";
		}
		else {
			Node * temp = head;
			while (temp != NULL) {
				cout << temp -> data << "--> ";
				temp = temp -> next;
			}
			cout << "NULL" << endl << endl;
		}	
  	}

    void Swap(int key1, int key2){
        Node* ptr1 = NodeExists(key1);
        Node* ptr2 = NodeExists(key2);
        swap(ptr1->data, ptr2->data);
    }

    void MakeWord(){
        if(head == NULL){
            cout << "Empty Linked List\n";
        }
        else{
            Swap(0,1);
            // PrintList();
            Swap(2,3);
            // PrintList();
            Swap(6,7);
            // PrintList();
        }
    }
};

int main(){
    Node* N = new Node(0,'C');
    SinglyLinkedList S;
    S.AppendNode(N);
    N = new Node(1,'S');
    S.AppendNode(N);
    N = new Node(2,'A');
    S.AppendNode(N);
    N = new Node(3,'R');
    S.AppendNode(N);
    N = new Node(4,'B');
    S.AppendNode(N);
    N = new Node(5,'B');
    S.AppendNode(N);
    N = new Node(6,'E');
    S.AppendNode(N);
    N = new Node(7,'L');
    S.AppendNode(N);
    S.PrintList();
    S.MakeWord();
    S.PrintList();
}
