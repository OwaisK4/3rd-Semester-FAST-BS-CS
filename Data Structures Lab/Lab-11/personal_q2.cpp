#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
const int T_S = 10;

class HashTableEntry{
	public:
		int key;
		int value;
		HashTableEntry* next;
		HashTableEntry(){
			key = 0;
			value = 0;
			next = NULL;
		}
		HashTableEntry(int k, int v){
			key = k;
			value = v;
			next = NULL;
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
		/*
		int HashFunc(int key){			// Division hash
			return key % T_S;
		}
		*/
		int HashFunc(int key){					// Multiplication hash
			float c = 0.17;
			return floor(T_S * fmod(key * c, 1));
		}
		/*
		int HashFunc(int key){					// Mid square hash
			long int x = key * key;
			if(x>99 && x <1000){
				return (x / 10) % 10 ;
			}	
			else if(x>999 && x <100000){
				return  (x / 10) % 100 ;
			}			
			else if(x>9999 && x <100000){
				return (x / 10) % 1000 ;
			}
		}
		*/
		/*
		int HashFunc(int key1, key2, key3){		// Folding hash
			return key1 + key2 + key3;
		}
		*/
		/*
		int HashFunc(int key){					// Radix hash
			int result = log(key);
			return result % 10000;
		}
		*/	
		void Insert(int key, int value){
			HashTableEntry* temp = new HashTableEntry(key, value);
			int hash = HashFunc(key);
			HashTableEntry* previous;
			HashTableEntry* current;
			if (t[hash] == NULL){
				t[hash] = temp;
			}
			else{
				previous = t[hash];
				current = t[hash];
				while (current != NULL){
					previous = current;
					current = current->next;
				}
				current = temp;
			}
		}
		HashTableEntry* SearchKey(int key){
			int hash = HashFunc(key);
			if (t[hash] != NULL)
				return t[hash];
			return NULL;
		}
		void Remove(int key){
			int hash = HashFunc(key);
			if (t[hash] != NULL){
				cout << "Deleted value " << t[hash]->value << " at " << key << "\n";
				HashTableEntry* previous = t[hash];
				HashTableEntry* current = t[hash];
				while (current != NULL){
					previous = current;
					current = current->next;
					delete previous;
				}
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
//	table.Print();
	return 0;
}