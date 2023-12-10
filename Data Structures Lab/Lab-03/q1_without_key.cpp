#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
	public:
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
	private:
		Node* head;
	public:
		SinglyLinkedList(){
			head = NULL;
		}
		SinglyLinkedList(Node *node){
			head = node;
			head->next = NULL;
		}
		void insert_at_head(int d){
			Node* temp = new Node(d);
			if (head == NULL){
				head = temp;
			}
			else{
				temp->next = head;
				head = temp;
			}
		}
		void insert_at_tail(int d){
			Node* temp = new Node(d);
			Node* current;
			if (head == NULL){
				head = temp;
				head->next = NULL;
			}
			else{
				for (current = head; current->next != NULL; current = current->next);
				current->next = temp;
				current->next->next = NULL;
			}
		}
		void traverse(){
			Node* current;
			for (current = head; current != NULL; current = current->next){
				cout << current->data << " ";
			}
		}
		
		
};

int main(){
	Node* first = new Node(1);
	SinglyLinkedList list(first);
	list.insert_at_head(2);
	list.insert_at_head(5);
	list.insert_at_tail(3);
	list.insert_at_tail(5);
	list.traverse();
	
	return 0;
}
