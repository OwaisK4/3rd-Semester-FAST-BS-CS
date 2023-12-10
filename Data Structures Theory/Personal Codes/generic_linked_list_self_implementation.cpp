#include <iostream>
using namespace std;

template<typename T>
class Node{
	public:
		T data;
		int key;
		Node* next;
	public:
		Node(){
			data = 0;
			key = 0;
			next = NULL;
		}
		Node(T d, int k = 0){
			data = d;
			key = k;
			next = NULL;
		}
};

template <typename T>
class SinglyLinkedList{
	private:
		Node<T>* head;
		static int key;
	public:
		SinglyLinkedList(){
			head = NULL;
		}
		SinglyLinkedList(Node<T> *node){
			head = node;
			head->next = NULL;
		}
		void insert_at_head(T d){
			Node<T>* temp = new Node<T>(d, ++key);
			if (head == NULL){
				head = temp;
				head->next = NULL;
			}
			else{
				delete temp;
				temp = new Node<T>(d, head->key);
				temp->next = head;
				head = temp;
				for (temp = head->next; temp != NULL; temp = temp->next){
					temp->key++;
					key = temp->key;
				}
//				key = temp->key;
			}
		}
		void insert_at_tail(T d){
			Node<T>* temp = new Node<T>(d, ++key);
			Node<T>* current;
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
		void insert_node_at_position(T d, int position){
			Node<T>* temp = new Node<T>(d, ++position);
			Node<T>* current;
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
			Node<T>* temp = head;
			head = head->next;
			delete temp;
		}
		void delete_tail(){
			if (head == NULL){
				cout << "Empty list\n";
				return;
			}
			Node<T>* temp;
			for (temp = head; temp->next->next != NULL; temp = temp->next);
			delete temp->next;
			temp->next = NULL;
		}
		void delete_from_postion(int k){
			Node<T>* previous = head;
			Node<T>* current = head->next;
			if (head->key == k){
				head = head->next;
				delete previous;
				return;
			}
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
		void delete_by_value(T value){
			Node<T>* previous = head;
			Node<T>* current = head->next;
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
			Node<T>* current;
			int i = 1;
			for (current = head; current != NULL; current = current->next, i++){
				cout << "Node #0" << i << ": ";
				cout << "Data = " << current->data << ", " << "Key = " << current->key << "\n";
			}
			cout << "\n";
		}
		void reverse(){
			Node<T>* current = head;
			Node<T>* previous_ptr = NULL;
			Node<T>* next_ptr = NULL;
			for (current = head; current != NULL; current = next_ptr){
				next_ptr = current->next;
				current->next = previous_ptr;
				previous_ptr = current;
			}
            head = previous_ptr;
		}
		void sort(){
			int size=0;
			Node<T>* current = head;
			for (current = head; current != NULL; current = current->next){
				size++;
			}
			Node<T>* previous = head;
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
			Node<T>* temp = head;
			int count = 0;
			for (; temp->next != NULL; temp = temp->next){
				Node<T> *ptr = temp->next;
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

template <typename T>
int SinglyLinkedList<T>::key = 0;

int main(){
	SinglyLinkedList<char> list;
	list.insert_at_head('A');
	list.insert_at_head('B');
	list.insert_at_head('C');
	list.traverse();
	list.delete_from_postion(1);
	list.traverse();
	return 0;
}
