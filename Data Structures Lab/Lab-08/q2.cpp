#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Node{
	public:
		int element;
		int priority;
		Node* next;
		Node(){
			element = 0;
			priority = 0;
			next = NULL;
		}
		Node(int e, int p){
			element = e;
			priority = p;
			next = NULL;
		}
};

class PriorityQueue{
	public:
		Node* front;
		PriorityQueue(){
			front = NULL;
		}
		void enqueue(int e, int p){ // Lower value of p indicates higher priority
			Node* temp = new Node(e, p);
			temp->next = front;
			front = temp;
		}
		Node* updated_dequeue(){
			Node* temp;
			if (front == NULL) //Empty queue
				return temp;
			else{
				temp = front;
				Node* previous = front;
				Node* current = front;
				while (current->next != NULL){
					if (current->next->priority < temp->priority){
						temp = current->next;
						previous = current;
					}						
					current = current->next;
				}
				if (temp == front){
					front = front->next;
					return temp;
				}
				else{
					previous->next = temp->next;
				}
				return temp;
			}
		}
};

int main(){
	srand(time(0));
	PriorityQueue queue;
	Node* temp;

	for (int i=0; i<10; i++){
		queue.enqueue(i, (float) rand() / RAND_MAX * 50.0);
	}	

	cout << "Value,\tPriority\n";
	for (int i=0; i<10; i++){
		temp = queue.updated_dequeue();
		if (temp == NULL){
			cout << "All elements dequeued.";
			break;
		}
		cout << temp->element << ",\t" << temp->priority;
		cout << "\n";
	}
	
	return 0;
}
