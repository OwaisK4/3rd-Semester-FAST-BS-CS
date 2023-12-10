#include<iostream>
using namespace std;

class Node{
    public:
        int key;
        int data;
        Node* next;

    Node(){
        key = 0;
        data = 0;
        next = NULL;
    }

    Node(int key, int data){
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

//1
    void PrependNode(Node* n){
        if(NodeExists(n->key) != NULL){
            cout << "Node with this Key " << n->key << " already exists!\n"; 
        }
        else{
            n->next = head;
            head = n;
        }
    }

//2
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

//3
    void InsertNodeAt(Node* n, int key){
        Node* ptr = NodeExists(key);
        if(ptr == NULL){
            cout << "No Node with this key " << key << " exists!\n";
        }
        else{
            n->next = ptr->next;
            ptr->next = n;
        }
    }
 
//4
    void DeleteNodeByValue(int data){
        if(head == NULL){
            cout << "Empty Linked List!\n";
        }
        else if(head!=NULL){
            if(head->data == data){
                head = head->next;
            }
            else{
                Node* ptr = NULL;
                Node* temp = head;
                while(temp->next != NULL){
                    if(temp->data == data){
                        ptr->next = temp->next;
                    }
                    ptr = temp;
                    temp = temp->next;
                }
            }
        }
    }

//5
    void DeleteHead(){
        if(head == NULL){
            cout << "Empty Linked List!\n";
        }
        else if(head!=NULL){
            head = head->next;
        }
    }

//6
    void DeleteTail(){
        if(head == NULL){
            cout << "Empty Linked List!\n";
        }
        else if(head!=NULL){
            Node* prev = NULL;
            Node* temp = head;
            while(temp->next!=NULL){
                prev = temp;
                temp = temp->next;
            }
            prev->next = NULL;
        }
    }

//7
    void DeleteNodeByKey(int key){
        if(head == NULL){
            cout << "Empty Linked List!\n";
        }
        else if(head!=NULL){
            if(head->key == key){
                head = head->next;
            }
            else{
                Node* temp = NULL;
                Node* prev = head;
                Node* current = head->next;

                while(current!=NULL){
                    if(current->key == key){
                        temp = current;
                        current = NULL;
                    }
                    else{
                        prev = prev->next;
                        current = current->next;
                    }
                }
                if(temp!=NULL){
                    prev->next = temp->next;
                }
                else{
                    cout << "Node with this key " << key << " does not exists";
                }
            }
        }
    }

    void PrintList() {
		if (head == NULL) {
			cout << "No Nodes in Singly Linked List";
		}
		else {
			Node * temp = head;
			while (temp != NULL) {
				cout << temp -> key << "," << temp -> data << "--> ";
				temp = temp -> next;
			}
            cout << "NULL" << endl << endl;
		}	
  	}
};

int main(){
    Node* N = new Node(0,1);
    SinglyLinkedList S;
    S.AppendNode(N);
    S.PrintList();
    N = new Node(1,2);
    S.AppendNode(N);
    S.PrintList();
    N = new Node(2,3);
    S.AppendNode(N);
    S.PrintList();
    N = new Node(3,4);
    S.AppendNode(N);
    S.PrintList();
    N = new Node(4,5);
    S.PrependNode(N);
    S.PrintList();
    N = new Node(5,6);
    S.InsertNodeAt(N,2);
    S.PrintList();
    S.DeleteNodeByKey(1);
    S.PrintList();
    S.DeleteHead();
    S.PrintList();
    S.DeleteTail();
    S.PrintList();
    S.DeleteNodeByValue(1);
    S.PrintList();
}
