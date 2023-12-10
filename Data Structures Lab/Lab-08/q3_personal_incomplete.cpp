#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int SHORT_SIZE = 10
const int LONG_SIZE = 100

class Element{
	public:
		int data;
		int priority;
		Element(){
			data = -1;
			priority = -1;
		}
		Element(int d, int p){
			data = d;
			priority = p;
		}
};

class PriorityQueue{
	public:
		Element ordered[SHORT_SIZE];	// Elements will be enqueued here only if they have a priority GREATER than threshold
		int front_ord, rear_ord;
		Element unordered[LONG_SIZE];
		int front_unord, rear_unord;
		int threshold;
		PriorityQueue(int threshold = 10){
			this->threshold = threshold;
			front_ord = -1;
			rear_ord = -1;
			front_unord = -1;
			rear_unord = -1;
		}
		void enqueue(Element temp){
			if (temp.priority > threshold){
				if (front_ord == 0 && rear_ord >= SHORT_SIZE-1)
					enqueue_in_unordered(temp);
				else
					enqueue_in_ordered(temp);
			}
			else{
				enqueue_in_unordered(temp);
			}
				
		}
		void enqueue_in_ordered(Element temp){
			if (front_ord == -1){
				front_ord = 0;
				rear_ord = 0;
				ordered[rear_ord] = temp;
			}
			else if (rear_ord >= SHORT_SIZE-1){
				for(int i=front_ord;i<=rear_ord;i++){
					ordered[i-front_ord] = ordered[i];
					rear_ord = rear_ord - front_ord;
					front_ord = 0;
					for(i = rear_ord; i>front_ord;i--){
						if(temp.priority>ordered[i].priority){
							ordered[i+1] = ordered[i];
						}
						else
							break;
						ordered[i+1] = temp;
						rear_ord++;
					}
				}
			}
			else{
				for(int i = rear_ord;i>=front_ord;i--){
					if(temp.priority>ordered[i].priority){
						ordered[i+1] = ordered[i];
					}
					else
						break;
				}
				ordered[i+1] = temp;
				r++;
			}
		}
		void enqueue_in_unordered(Element temp){
			if (front_unord == -1){
				front_unnord = 0;
				rear_unord = 0;
				ordered[rear_unord] = temp;
			}
			else if (front_ord == 0 && rear_ord >= SHORT_SIZE-1)
				cout << "Full unordered queue.\n";
			
		}
};

int main(){
	return 0;
}
