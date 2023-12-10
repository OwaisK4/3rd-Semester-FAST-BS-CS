#include <iostream>
#include <utility>
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

class DoublyCircularLinkedList{
	public:
		Node* head;
	public:
		DoublyCircularLinkedList(){
			head = NULL;
		}
		DoublyCircularLinkedList(Node *node){
			head = node;
			node->next = head;
		}
		void prepend(int k, int d){
			Node *temp = new Node(k, d);
			Node *current;
			if (head == NULL){
				head = temp;
				temp->next = head;
				head->prev = temp;
			}
			else{
				for (current = head; current->next != head; current = current->next);
				current->next = temp;
				temp->prev = current;
				temp->next = head;
				head->prev = temp;
				head = temp;
			}
		}
		void append(int k, int d){
			Node *temp = new Node(k, d);
			Node *current;
			if (head == NULL){
				head = temp;
				temp->next = head;
				head->prev = temp;
			}
			else{
				for (current = head; current->next != head; current = current->next);
				current->next = temp;
				temp->prev = current;
				temp->next = head;
				head->prev = temp;
			}
		}
		void insert(int position, int k, int d){
			Node *current = new Node(k, d);
			Node* temp = Node_Exists(position);
			
			if (temp != NULL){
				if (temp->next == head){
					temp->next = current;
					current->prev = temp;
					current->next = head;
					head->prev = current;
				}
				else{
					current->next = temp->next;
					temp->next = current;
					current->prev = temp;
					current->next->prev = current;
				}
				cout << "Inserted new node after node of key = " << position << "\n";				
			}
			else{
				cout << "Node with given key does not exist.\n";
			}
		}
		void delete_head(){
			if (head != NULL){
				Node *temp;
				for (temp = head; temp->next != head; temp = temp->next);
				temp->next = head->next;
				Node *current = head;
				head = head->next;
				head->prev = temp;
				delete current;
			}
			
		}
		void delete_tail(){
			if (head != NULL){
				Node *temp;
				for (temp = head; temp->next->next != head; temp = temp->next);
				Node *current = temp->next;
				temp->next = head;
				head->prev = temp;
				delete current;
			}
		}
		void delete_node(int position){
			Node* current = Node_Exists(position);
			if (current != NULL){
				if (current == head){
					delete_head();
				}
				else if (current->next == head){
					delete_tail();
				}
				else{
					Node* temp;
					for (temp = head; temp->next != current; temp = temp->next);
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
			Node* current = head;
			do{
				cout << "Key: " << current->key << ", Data: " << current->data << "\n";
				current = current->next;
			} while (current != head);
			cout << "\n";
		}
		Node* Node_Exists(int k){
			Node* current = head;
			Node* temp = NULL;
			do{
				if (current->key == k){
					temp = current;
				}
				current = current->next;
			} while (current != head);
			return temp;
		}
		void search(int key){
			Node* temp = Node_Exists(key);
			if (temp != NULL){
				cout << "Node found with key = " << temp->key << " and data = " << temp->data << ".\n";
			}
			else{
				cout << "Node with given key does not exist.\n";
			}
		}
		void remove_duplicates(){
			Node *temp = head;
			Node *current, *extra;
			while (temp->next != head){
				current = temp->next;
				while (current != temp){
					if (temp->data == current->data){
						temp = head;
						delete_node(current->key);
						break;
					}
					current = current->next;
				} 
				temp = temp->next;
			} 
		}
};


int main(){
	Node* n = new Node(1,6);
	DoublyCircularLinkedList list(n);
	list.append(2,9);
	list.append(3,9);
	list.prepend(4,20);
	list.prepend(5, 20);
	list.insert(4, 68, 240);
	list.traverse();
	list.delete_node(68);
	list.traverse();
	list.remove_duplicates();
	list.traverse();
	return 0;
}
