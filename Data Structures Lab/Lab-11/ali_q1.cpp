#include<iostream>
using namespace std;
#define N 10

class HashNode{
public:
// int key;
int value;

HashNode(){
// key=0;
value=0;
}
HashNode(int value){
this->value = value;
}
};
class HashTable{
HashNode **table;

public:
HashTable(){
table = new HashNode* [N];
for(int i=0;i<N;i++){
table[i] = NULL;
}
}
int HashFun(int value){
return value % N;
}
void insert(int value){
int key = HashFun(value);
table[key] = new HashNode(value);
}
void search(int key){

if(table[HashFun(key)]!=NULL){
cout<<endl<<table[key]->value;
}
else{
cout<<"\nkey not found";
}
}
void remove(int key){
if(table[HashFun(key)]!=NULL){
delete table[key];
table[key]=NULL;
cout<<"\nkey and value deleted";
}
else{
cout<<"\nkey does not exist";
}
}
// ~HashTable(){
// for(int i = 0 ;i<N;i++){
// if(table[i]==NULL)
//
// }
// }
};
int main(){
HashTable t;

for(int i=10;i<=20;i++){
t.insert(i);
}
t.remove(3);
t.search(3);
t.search(2);

}
