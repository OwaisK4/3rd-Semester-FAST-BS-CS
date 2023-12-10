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
	public:
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
		Node* merge(DoublyLinkedList first, DoublyLinkedList second){
			Node* head_1 = first.head;
			Node* head_2 = second.head;
			Node* current;
			for (current = head_1; current->next != NULL; current = current->next);
			current->next = head_2;
			int key = current->key + 1;
			for (current = head_2; current != NULL; current = current->next){
				current->key = key++;
			}
			return head_1;
		}
		void BubbleSort(){
			Node *temp = head;
			Node *current, *previous;
			while (temp->next != NULL){
				previous = head;
				current = head->next;
				while (current != NULL){
					if (previous->data < current->data){
						swap(previous->data, current->data);
						swap(previous->key, current->key);
					}
					previous = previous->next;
					current = current->next;
				}
				temp = temp->next;
			}
		}
		void SelectionSort(){
			Node *temp, *current, *min_index;
			for (temp = head; temp->next != NULL; temp = temp->next){
				min_index = temp;
				for (current = temp; current != NULL; current = current->next){
					if (current->data > min_index->data)
						min_index = current;
				}
				swap(temp->data, min_index->data);
				swap(temp->key, min_index->key);
			}
		}
		void InsertionSort(){
			Node* sorted = NULL;
        	Node* current = head;
	        while (current != NULL) {
    	        Node* next = current->next;
    	        if (sorted == NULL || sorted->data <= current->data){
            		current->next = sorted;
		            sorted = current;
    	    	}
        		else {
	            	Node* extra = sorted;
		            while (extra->next != NULL && extra->next->data > current->data) {
        		        extra = extra->next;
            		}
	            	current->next = extra->next;
    	        	extra->next = current;
        		}
	            current = next;
        	}
    	    head = sorted;
    	}
    	
};

int main(){
//	Node* n = new Node(1,6);
	DoublyLinkedList odd_list;
	DoublyLinkedList even_list;

	for (int i=0, j=2; j<=10; i++, j+=2){
		even_list.append(i, j);
	}
	for (int i=0, j=1; j<=10; i++, j+=2){
		odd_list.append(i, j);
	}
	cout << "Even list:\n";
	even_list.traverse();
	cout << "Odd list:\n";
	odd_list.traverse();
	
	DoublyLinkedList list(list.merge(even_list, odd_list));
	cout << "Combined list:\n";
	list.traverse();
//	list.BubbleSort();
//	list.SelectionSort();
	list.InsertionSort();
	cout << "Sorted list:\n";
	list.traverse();
	return 0;
}	


		/*
		void InsertionSort(){
			Node *sorted = new Node(head->key, head->data);
			Node *current, *temp, *next;
			for (current = head->next; current->next != NULL;){
				next = current->next;
				if (current->data < sorted->data){
					current->next = sorted;
					sorted = current;
				}
				else{
					for (temp = sorted; temp->next != NULL; temp = temp->next){
						if (current->data < temp->data)
							break;
					}
					if (temp == NULL){
						temp = current;
					}
					else if (temp->next == NULL){
						temp->next = current;
						current->next = NULL;
					}
					else {
						current->next = temp->next;
						temp->next = current;
					}
				}
				current = next;
			}
		}
		*/
