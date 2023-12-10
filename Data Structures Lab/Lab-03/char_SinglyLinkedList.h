#include <iostream>
using namespace std;

class Node{
	public:
		char data;
		int key;
		Node* next;
	public:
		Node(){
			data = 0;
			key = 0;
			next = NULL;
		}
		Node(char d, int k = 0){
			data = d;
			key = k;
			next = NULL;
		}
};

class SinglyLinkedList{
	private:
		Node* head;
		static int key;
	public:
		SinglyLinkedList(){
			head = NULL;
		}
		SinglyLinkedList(Node *node){
			head = node;
			head->next = NULL;
		}
		void insert_at_head(char d){
			Node* temp = new Node(d, ++key);
			if (head == NULL){
				head = temp;
			}
			else{
				delete temp;
				temp = new Node(d, head->key);
				temp->next = head;
				head = temp;
				for (temp = head->next; temp != NULL; temp = temp->next){
					temp->key++;
					key = temp->key;
				}
//				key = temp->key;
			}
		}
		void insert_at_tail(char d){
			Node* temp = new Node(d, ++key);
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
		void insert_node_at_position(char d, int position){
			Node* temp = new Node(d, ++position);
			Node* current;
			for (current = head; current != NULL;current = current->next){
				if (current->key == position){
					temp->next = current->next;
					current->next = temp;
					for (; temp != NULL; temp = temp->next){
						temp->key++;
						key = temp->key;
					}
					return;
				}
			}
			cout << "Position not found.\n";
			delete temp;
			return;
		}
		void delete_head(){
			if (head == NULL){
				cout << "Empty list\n";
				return;
			}
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		void delete_tail(){
			if (head == NULL){
				cout << "Empty list\n";
				return;
			}
			Node* temp;
			for (temp = head; temp->next->next != NULL; temp = temp->next);
			delete temp->next;
			temp->next = NULL;
		}
		void delete_from_postion(int k){
			Node* previous = head;
			Node* current = head->next;
			for (; previous != NULL, current != NULL; current = current->next, previous = previous->next){
				if (current->key == k){
					previous->next = current->next;
					delete current;
					return;
				}
			}
			cout << "Position not found.\n";
			return;
		}
		void delete_by_value(char value){
			Node* previous = head;
			Node* current = head->next;
			for (; previous != NULL, current != NULL; current = current->next, previous = previous->next){
				if (current->data == value){
					previous->next = current->next;
					delete current;
					return;
				}
			}
			cout << "Value not found.\n";
			return;
		}
		void traverse(){
			Node* current;
			int i = 1;
			for (current = head; current != NULL; current = current->next, i++){
				cout << "Node #0" << i << ": ";
				cout << "Data = " << current->data << ", " << "Key = " << current->key << "\n";
			}
			cout << "\n";
		}
		void update_data_by_key(char data, int key){
			Node* current;
			for (current = head; current != NULL; current = current->next){
				if (current->key == key){
					swap(current->data, data);
					return;
				}
			}
			cout << "Given position not found in list.";
		}
		void exchange_node(int position1, int position2){
			Node* current = head;
			Node* first = NULL;
			Node* second = NULL;
			for (current = head; current != NULL; current = current->next){
				if (current->key == position1)
					first = current;
				if (current->key == position2)
					second = current;
			}
			if (first == NULL || second == NULL){
				cout << "Invalid keys.\n";
			}
			else{
				swap(first->data, second->data);
				swap(first->key, second->key);
			}
		}
};

int SinglyLinkedList::key = 0;
