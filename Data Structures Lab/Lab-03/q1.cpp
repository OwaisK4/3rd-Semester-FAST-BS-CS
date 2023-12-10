#include <iostream>
#include "int_SinglyLinkedList.h"
using namespace std;

int main(){
	Node* first = new Node(2);
	SinglyLinkedList list(first);
	list.insert_at_head(4);
	list.insert_at_head(8);
	list.insert_at_tail(16);
	list.insert_at_tail(32);
	list.insert_node_at_position(64, 0);
	list.traverse();
	
	cout << "After deletion of 4 nodes(head, tail, position #2, data=2):\n";
	list.delete_head();
	list.delete_tail();	
	list.delete_from_postion(2);
	list.delete_by_value(2);
	list.traverse();
	
	return 0;
}
