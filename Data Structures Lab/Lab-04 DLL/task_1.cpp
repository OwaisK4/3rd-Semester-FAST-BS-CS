#include <iostream>
using namespace std;

class Node{
	public:
		int key;
		int data;
		Node* next;
		Node* prev;
	public:
		Node(){
			key = 0;
			data = 0;
			next = NULL;
			prev = NULL;
		}
		Node(int k, int d){
			key = k;
			data = d;
			next = NULL;
			prev = NULL;
		}
};

class DoublyLinkedList{
	private:
		Node* head;
	public:
		DoublyLinkedList(){
			head = NULL;
		}
		DoublyLinkedList(Node *node){
			head = node;
		}
		void prepend(int k, int d){
			Node *temp = new Node(k, d);
			if (head == NULL){
				head = temp;
				head->next = NULL;
				head->prev = NULL;
			}
			else{
				temp->next = head;
				temp->prev = NULL;
				head->prev = temp;
				head = temp;
			}
		}
		void append(int k, int d){
			Node *temp = new Node(k, d);
			if (head == NULL){
				head = temp;
				head->next = NULL;
				head->prev = NULL;
			}
			else{
				Node* current;
				for (current = head; current->next != NULL; current = current->next);
				current->next = temp;
				temp->prev = current;
			}
		}
		void insert(int position, int k, int d){
			Node *current = new Node(k, d);
			Node* temp = node_exists(position);
			
			if (temp != NULL){
				if (temp->next == NULL){
					temp->next = current;
					current->next = NULL;
					current->prev = temp;
				}
				else{
					current->next = temp->next;
					temp->next->prev = current;
					temp->next = current;
					current->prev = temp;
					cout << "Inserted new node after node of key = " << position << "\n";
				}
				
			}
			else{
				cout << "Node with given key does not exist.\n";
			}
		}
		void delete_head(){
			head = head->next;
			delete head->prev;
			head->prev = NULL;
		}
		void delete_tail(){
			Node* current;
			for (current = head; current->next->next != NULL; current = current->next);
			delete current->next;
			current->next = NULL;
		}
		void delete_node(int position){
			Node* current = node_exists(position);
			if (current != NULL){
				if (current == head){
					delete_head();
				}
				else if (current->next == NULL){
					delete_tail();
				}
				else{
					Node* temp = current->prev;
					temp->next = current->next;
					current->next->prev = temp;
					delete current;
				}
				cout << "Deleted node of key = " << position << "\n";
			}
			else{
				cout << "Node with given key does not exist.\n";
			}
		}
		void traverse(){
			Node* current;
			cout << "\n";
			for (current = head; current != NULL; current = current->next){
				cout << "Key: " << current->key << ", Data: " << current->data << "\n";
			}
			cout << "\n";
		}
		Node* node_exists(int key){
			Node* current;
			for (current = head; current != NULL; current = current->next){
				if (current->key == key)
					return current;
			}
			return NULL;
		}
		void search(int key){
			Node* temp = node_exists(key);
			if (temp != NULL){
				cout << "Node found with key = " << temp->key << " and data = " << temp->data << ".\n";
			}
			else{
				cout << "Node with given key does not exist.\n";
			}
		}
};

int main(){
	Node* n = new Node(1,6);
	DoublyLinkedList list(n);
	list.append(2,9);
	list.append(3,15);
	list.prepend(4,20);
	list.prepend(5, 24);
//	list.traverse();
//	list.search(4);
//	list.search(6);
	list.insert(4, 68, 240);
	list.traverse();
//	list.delete_node(4);
//	list.delete_head();
//	list.delete_tail();
	list.delete_node(4);
	list.traverse();
	return 0;
}
