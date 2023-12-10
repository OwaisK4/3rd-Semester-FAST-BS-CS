#include <iostream>
using namespace std;

template <typename T>
class DoublyCircularLinkedList{
	public:
		
class Node{
	public:
		Node(){
			key = 0;
			data = 0;
			next = NULL;
			previous = NULL;
		}
		Node(T d, int k){
			key = k;
			data = d;
			next = NULL;
			previous = NULL;
		}
	public:
		int key;
		T data;
		Node* next;
		Node* previous;
};
		
		DoublyCircularLinkedList(){
			head = NULL;
			tail = NULL;
		}
 		void insert_head(T d, int k){
			Node* newNode = new Node(d, k);
			if (head == tail && head == NULL){
				head = newNode;
				tail = newNode;
			}
			else{
				newNode->next = head;
				head->previous = newNode;
				head = newNode;
				tail->next = head;
				head->previous = tail;
			}
		}
		void insert_tail(T d, int k){
			Node* newNode = new Node(d, k);
			if (head == tail && head == NULL){
				head = newNode;
				tail = newNode;
			}
			else{
				newNode->next = head;
				head->previous = newNode;
				tail->next = newNode;
				newNode->previous = tail;
				tail = newNode;
			}
		}
		Node* Node_exists(int k){
			Node* ptr = NULL;
			Node *temp = head;
			for (; temp != tail; temp = temp->next){
				if (temp->key == k)
					ptr = temp;
			}
			if (temp->key == k)
				ptr = temp;
//			do{
//				if (temp->key == k)
//					ptr = temp;
//				temp = temp->next;
//			} while (temp != tail);
			return ptr;
		}
		void traverse(){
			Node* temp = head;
			for (; temp != tail; temp = temp->next){
				cout << "Key = " << temp->key << ", Data = " << temp->data << "\n";
			}
			cout << "Key = " << temp->key << ", Data = " << temp->data << "\n";		//Because tail pointer must pe printed and tail->next is the same as head.
		}
	public:
		Node* head;
		Node* tail;
};

int main(){
	DoublyCircularLinkedList<int> list;
	list.insert_head(420, 1);
	list.insert_head(69, 2);
	list.insert_head(21, 3);
	list.insert_tail(721, 4);
//	list.print(0);
//	list.print(1);
	list.traverse();
	cout << list.Node_exists(1)->data;
	return 0;
}
