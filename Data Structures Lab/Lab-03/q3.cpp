#include <iostream>
#include "char_SinglyLinkedList.h"
using namespace std;

int main(){
	Node* first = new Node('C');
	SinglyLinkedList list(first);
	list.insert_at_tail('S');
	list.insert_at_tail('A');
	list.insert_at_tail('R');
	list.insert_at_tail('B');
	list.insert_at_tail('B');
	list.insert_at_tail('E');
	list.insert_at_tail('L');
	list.traverse();
	
	list.exchange_node(0, 1);
	list.exchange_node(2, 3);
	list.exchange_node(4, 5);
	list.exchange_node(6, 7);
	list.traverse();
	return 0;
}
