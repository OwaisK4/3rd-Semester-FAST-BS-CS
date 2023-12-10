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
};

int main(){
    Node* N = new Node(0,'S');
    SinglyLinkedList S;
    S.AppendNode(N);
    N = new Node(1,'A');
    S.AppendNode(N);
    N = new Node(2,'T');
    S.AppendNode(N);
    N = new Node(3,'A');
    S.AppendNode(N);
    S.PrintList();
    S.UpdateNodeByKey(0,'D');
    S.PrintList();
}
