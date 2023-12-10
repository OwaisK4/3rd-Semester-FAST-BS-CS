#include <iostream>
#include "char_SinglyLinkedList.h"
using namespace std;

int main(){
	Node* first = new Node('A');
	SinglyLinkedList list(first);
	list.insert_at_head('T');
	list.insert_at_head('A');
	list.insert_at_head('S');
	list.traverse();
	
	list.update_data_by_key('D', 0);
	list.traverse();
	return 0;
}