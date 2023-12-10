#include <iostream>
using namespace std;

class Node{
	public:
		int key;
		int data;
		Node* next;
	public:
		Node(){
			key = 0;
			data = 0;
			next = NULL;
		}
		Node(int k, int d){
			key = k;
			data = d;
			next = NULL;
		}
};

class SinglyCircularLinkedList{
	private:
		Node* head;
	public:
		SinglyCircularLinkedList(){
			head = NULL;
		}
		SinglyCircularLinkedList(Node *node){
			head = node;
			node->next = head;
		}
		void prepend(int k, int d){
			Node *temp = new Node(k, d);
			Node *current;
			if (head == NULL){
				temp->next = head;
				head = temp;
			}
			else{
				for (current = head; current->next != head; current = current->next);
				current->next = temp;
				temp->next = head;
				head = temp;
			}
		}
		void append(int k, int d){
			Node *temp = new Node(k, d);
			Node *current;
			if (head == NULL){
				temp->next = head;
				head = temp;
			}
			else{
				for (current = head; current->next != head; current = current->next);
				current->next = temp;
				temp->next = head;
			}
		}
		void insert(int position, int k, int d){
			Node *current = new Node(k, d);
			Node* temp = Node_Exists(position);
			
			if (temp != NULL){
				if (temp->next == NULL){
					temp->next = current;
					current->next = head;
				}
				else{
					current->next = temp->next;
					temp->next = current;
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
				delete current;
				cout << "Deleted head node.\n";
			}
			
		}
		void delete_tail(){
			if (head != NULL){
				Node *temp;
				for (temp = head; temp->next->next != head; temp = temp->next);
				Node *current = temp->next;
				temp->next = head;
				delete current;
				cout << "Deleted tail node.\n";
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
};

int main(){
	Node* n = new Node(1,6);
	SinglyCircularLinkedList list(n);
	list.append(2,9);
	list.append(3,15);
	list.prepend(4,20);
	list.prepend(5, 24);
	list.traverse();
	list.search(4);
	list.search(6);
	list.insert(4, 68, 240);
	list.traverse();
	list.delete_head();
	list.delete_tail();
	list.delete_node(68);
	list.traverse();
	return 0;
}
