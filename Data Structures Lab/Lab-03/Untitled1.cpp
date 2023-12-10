#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
		Node(){
			data = 0;
			next = NULL;
		}
		Node(int d){
			data = d;
			next = NULL;
		}
};

class SinglyLinkedList{
	public:
		Node* head = NULL;
		void insert_Tail(Node* n, int d){
			if (head == NULL){
//				Node* n = new Node(d);
//				head = n;
				head = new Node(d);
				head->next = NULL;
			}
			else{
//				Node* temp = head;
//				while (temp->next != NULL)
//					temp = temp->next;
//				temp->next = new Node(d);
				n = head;
				while (n->next != NULL){
					n = n->next;
				}
				n->next = new Node(d);
				n->next->next = NULL;
			}
		}
		void insert_Head(Node* n, int d){
			if (head == NULL){
				head = new Node(d);
				head->next = NULL;
			}
			else{
				n = new Node(d);
				n->next = head;
				head = n;
			}
		}
		void print(Node *n){
			n = head;
			while (n != NULL){
				cout << n->data << " ";
				n = n->next;
			}
			cout << "\n";
//			while (temp != NULL){
//				cout << temp->data << " ";
//				temp = temp->next;
//			}
		}
};

int main(){
	SinglyLinkedList list;
	Node* head = NULL;
//	list.insert_Head(head, 786);
//	list.print(head);
	list.insert_Tail(head, 5);
	list.print(head);
	list.insert_Tail(head, 10);
	list.print(head);
	list.insert_Tail(head, -23);
	list.print(head);
	list.insert_Tail(head, 69);
	list.print(head);
	list.insert_Head(head, 420);
	list.print(head);
	return 0;
}