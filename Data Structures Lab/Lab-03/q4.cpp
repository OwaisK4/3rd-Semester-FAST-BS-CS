#include <iostream>
#include "int_SinglyLinkedList.h"
using namespace std;

int main(){
	Node* first = new Node(2);
	SinglyLinkedList list(first);
	list.insert_at_head(4);
	list.insert_at_head(8);
	list.insert_at_tail(8);
	list.insert_at_tail(32);
	list.insert_node_at_position(64, 0);
	cout << "Original linked list:\n";
	list.find_duplicates();
	list.traverse();
	
	cout << "Sorted linked list:\n";
	list.sort();
	list.traverse();
	
	cout << "Reversed linked list:\n";
	list.reverse();
	list.traverse();
	
	return 0;
}