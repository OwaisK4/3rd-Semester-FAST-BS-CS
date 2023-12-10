#include <iostream>
#include "..\Lab-04 DLL\DoublyLinkedList.h"
using namespace std;

void Merge(Node*& first, Node*& second){
	Node* merged = new Node;
    Node* temp = new Node;
    
    merged = temp;
	
	while (first != NULL && second != NULL){
		if (first->data < second->data){
			temp->next = first;
			first = first->next;
		}
		else{
			temp->next = second;
			second = second->next;
		}
		temp = temp->next;
	}
	while (first != NULL){
		temp->next = first;
		first = first->next;
		temp = temp->next;
	}
	while (second != NULL){
		temp->next = second;
		second = second->next;
		temp = temp->next;
	}
	first = merged->next;
}

Node* middle(Node* headNode){
	Node* slow = headNode;
	Node* fast = headNode->next;
	
	while (fast != NULL){
		fast = fast->next;
		if (fast != NULL){
			fast = fast->next;
			slow = slow->next;
		}
	}
	return slow;
}

void MergeSort(Node* left, Node* mid, Node* right){
	if (left->next == NULL)
		return;
	mid = middle(left);
	right = mid->next;
	mid->next = NULL;
	MergeSort(left, mid, right);
	MergeSort(right, mid, right);
	Merge(left, right);
}

int main(){
	DoublyLinkedList list;
	list.append(0, 5);
	list.append(1, 25);
	list.append(2, 12);
	list.append(3, 32);
	list.append(4, 44);
	list.append(5, 23);
	list.traverse();
	Node* mid = new Node;
	Node* right = new Node;
	MergeSort(list.getHead(), mid, right);
	list.traverse();
	return 0;
}
