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

    void reverse(){
        if(head == NULL){
            cout << "Empty Linked List\n";
        }
        else{
            Node* currentptr = head;
            Node* prevptr = NULL;
            Node* nextptr = NULL;
    
            while (currentptr != NULL) {
                nextptr = currentptr->next;
                currentptr->next = prevptr;
                prevptr = currentptr;
                currentptr = nextptr;
            }
            head = prevptr;
        }
    }

    void Sort(){
        Node* temp = head;
        int count = 0;

        while (temp->next!=NULL){
            temp = temp->next;
            count++;
        }

        while (temp != NULL) {
            Node* ptr = temp;
            while (ptr->next != NULL) {
                if (temp->data > ptr->data){
                    swap(temp->data, ptr->data);
                    break;
                }
                ptr = ptr->next;
            }
            temp = temp->next;
        }
    }

    void NoOfDuplicates(){
        Node* temp = head;
        int count = 0;
        while (temp->next != NULL) {
            Node *ptr = temp->next;
            while (ptr != NULL) {
                if (temp->data == ptr->data) {
                    count++;
                    break;
                }
                ptr = ptr->next;
            }
            temp = temp->next;
        }
        cout << count << " Duplicate found in this Linked List\n";
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
    Node* N = new Node(0,4);
    SinglyLinkedList S;
    S.AppendNode(N);
    N = new Node(1,3);
    S.AppendNode(N);
    N = new Node(2,2);
    S.AppendNode(N);
    N = new Node(3,1);
    S.AppendNode(N);
    S.PrintList();
    // S.reverse();
    // S.PrintList();
    S.Sort();
    S.PrintList();
    // S.NoOfDuplicates();
}
