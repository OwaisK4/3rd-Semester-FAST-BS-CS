#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		int key;
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

class SinglyLinkedList{
	private:
		Node* head;
	public:
		SinglyLinkedList(){
			head = NULL;
		}
		SinglyLinkedList(Node* node){
			head = node;
		}
		Node* get_head(){
			return head;
		}
		void prepend(int k, int d){
			Node* newNode = new Node(k, d);
			if (head == NULL){
				head = newNode;
			}
			else{
				newNode->next = head;
				head = newNode;
			}
		}
		void append(int k, int d){
			Node* newNode = new Node(k, d);
			if (head == NULL){
				head = newNode;
			}
			else{
				Node* current;
				for (current = head; current->next != NULL; current = current->next);
				current->next = newNode;
			}
		}
		void traverse(){
			Node* current;
			for (current = head; current != NULL; current = current->next){
//				cout << "Key: " << current->key << ", Data = " << current->data;
				cout << "(" << current->key << ", " << current->data << ") ";
				if (current->next != NULL){
					cout << "-> ";
				}
			}
			cout << endl;
		}
		void sortAscending(){
			Node* temp;
			Node* previous;
			Node* current;
			for (temp = head; temp->next != NULL; temp = temp->next){
				previous = head;
				current = head->next;
				while (current != NULL){
					if (previous->data > current->data){
						swap(previous->key, current->key);
						swap(previous->data, current->data);
					}
					previous = previous->next;
					current = current->next;
				}
			}
		}
		void sortDescending(){
			Node* temp;
			Node* previous;
			Node* current;
			for (temp = head; temp->next != NULL; temp = temp->next){
				previous = head;
				current = head->next;
				while (current != NULL){
					if (previous->data < current->data){
						swap(previous->key, current->key);
						swap(previous->data, current->data);
					}
					previous = previous->next;
					current = current->next;
				}
			}
		}
};

SinglyLinkedList combine(SinglyLinkedList first, SinglyLinkedList second){
	SinglyLinkedList list;
	Node* temp1 = first.get_head();
	Node* temp2 = second.get_head();
	int i, value;
	for (i=0 ; temp1 != NULL, temp2 != NULL; temp1 = temp1->next, temp2 = temp2->next){
		value = temp1->data / temp2->data;
		list.append(i, value);
		i++;
	}
	return list;
}

int main(){
	SinglyLinkedList M;
	M.append(0, 6);
	M.append(1, 24);
	M.append(2, 18);
	M.append(3, 30);
	M.append(4, 12);
	cout << "Format: (Key, Value)\n\n";
	cout << "List M: ";
	M.traverse();
	M.sortDescending();
//	M.traverse();
	
	
	SinglyLinkedList N;
	N.append(0, 2);
	N.append(1, 4);
	N.append(2, 6);
	N.append(3, 1);
	N.append(4, 3);
	cout << "\nList N: ";
	N.traverse();
	N.sortAscending();
//	N.traverse();
	
	SinglyLinkedList O = combine(M, N);
	cout << "\nList O: ";
	O.traverse();
	O.sortAscending();
	cout << "\nAscending order of List O: ";
	O.traverse();
	return 0;
}
