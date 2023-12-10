#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		int key;
		Node* next;
	public:
		Node(){
			data = 0;
			key = 0;
			next = NULL;
		}
		Node(int d, int k = 0){
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
		void insert_at_head(int d){
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
		void insert_at_tail(int d){
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
		void insert_node_at_position(int d, int position){
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
		void delete_by_value(int value){
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
		void reverse(){
			Node* current = head;
			Node* previous_ptr = NULL;
			Node* next_ptr = NULL;
			for (current = head; current != NULL; current = next_ptr){
				next_ptr = current->next;
				current->next = previous_ptr;
				previous_ptr = current;
			}
            head = previous_ptr;
		}
		void sort(){
			int size=0;
			Node* current = head;
			for (current = head; current != NULL; current = current->next){
				size++;
			}
			Node* previous = head;
			current = head->next;
			for (int i=0; i<size - 1; i++){
				for (int j=0; j < size - i - 1; j++){
					if (previous->data > current->data){
//						swap<Node>(*previous, *current);
						swap(previous->data, current->data);
						swap(previous->key, current->key);
					}
					previous = previous->next;
					current = current->next;
				}
				previous = head;
				current = head->next;
			}
		}
		void find_duplicates(){
			Node* temp = head;
			int count = 0;
			for (; temp->next != NULL; temp = temp->next){
				Node *ptr = temp->next;
				while (ptr != NULL){
					if (temp->data == ptr->data) {
						count++;
						break;
					}
					ptr = ptr->next;
				}
			}
			cout << "There are " << count << " duplicates in given list.\n";
		}
};

int SinglyLinkedList::key = 0;
