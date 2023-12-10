#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
const int T_S = 10;

class HashTableEntry{
	public:
		int key;
		int value;
		HashTableEntry(){
			key = 0;
			value = 0;
		}
		HashTableEntry(int k, int v){
			key = k;
			value = v;
		}
};

class HashMapTable{
	private:
		HashTableEntry** t;
	public:
		HashMapTable(){
			t = new HashTableEntry*[T_S];
//			memset(t, NULL, sizeof(t) * T_S);
			for (int i=0; i<T_S; i++){
				t[i] = NULL;
			}
		}
		int HashFunc(int key){
			return key % T_S;
		}
		void Insert(int key, int value){
			HashTableEntry* temp = new HashTableEntry(key, value);
			int hash = HashFunc(key);
			/*
			while (t[hash] != NULL && t[hash]->key != temp->key){
				hash = HashFunc(hash+1);
			}
			*/
			if (t[hash] != NULL){
				delete t[hash];
			}
			t[hash] = temp;
		}
		HashTableEntry* SearchKey(int key){
			int hash = HashFunc(key);
//			while (t[hash]->key != key){
//				hash = HashFunc(hash+1);
//			}
			if (t[hash] != NULL)
				return t[hash];
			return NULL;
		}
		void Remove(int key){
			int hash = HashFunc(key);
//			while (t[hash]->key != key){
//				hash = HashFunc(hash+1);
//			}
			if (t[hash] != NULL){
				cout << "Deleted value " << t[hash]->value << " at " << key << "\n";
				delete t[hash];
				t[hash] = NULL;
			}
			else{
				cout << "Given key does not exist.\n";
			}
		}
		~HashMapTable(){
			for (int i=0; i<T_S; i++){
				delete t[i];
			}
			delete [] t;
		}
		void Print(){
			for (int i=0; i<T_S; i++){
				if (t[i] == NULL){
					cout << 0 << ", " << 0 << "\n";
				}
				else{
					cout << t[i]->key << ", " << t[i]->value << "\n";
				}
			}
			cout << "\n";
		}
};

int main(){
	srand(time(0));
	HashMapTable table;
	for (int i=0; i<10; i++){
		table.Insert((float) rand() / RAND_MAX * 50.0, i);
	}
	table.Print();
	HashTableEntry* search = table.SearchKey(21);
	if (search == NULL)
		cout << "Given key not found.\n";
	else
		cout << "Key " << 21 << " found at: " << search->key << " and contains: " << search->value << "\n";
	table.Remove(10);
	cout << "\n";
	table.Print();
	return 0;
}
