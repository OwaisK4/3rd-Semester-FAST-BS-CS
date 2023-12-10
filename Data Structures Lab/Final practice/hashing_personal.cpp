#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int TABLE_SIZE = 128;

class HashEntry{
    public:
        int key;
        int value;
        HashEntry(int k, int v){
            key = k;
            value = v;
        }
};

class HashMap{
    public:
        HashEntry** table;
        HashMap(){
            table = new HashEntry*[TABLE_SIZE];
            for (int i=0; i<TABLE_SIZE; i++){
                table[i] = NULL;
            }
        }
        int HashFunc(int key){
            return key % TABLE_SIZE;
        }
        void Insert(int key, int value){
            int hash = HashFunc(key);
            while (table[hash] != NULL && table[hash]->key != key){
                hash = HashFunc(key + 1);
            }
            if (table[hash] != NULL)
                delete table[hash];
            table[hash] = new HashEntry(key, value);
        }
        void Print(){
            cout << "Hash Table:\n";
            for (int i=0; i < TABLE_SIZE; i++){
                if (table[i] != NULL){
                    cout << "Entry " << i << ":\tKey = " << table[i]->key << ", Value = " << table[i]->value << "\n";
                }
            }
        }
};

int main(){
    srand(time(0));
    HashMap map;
    for (int i=0; i<10; i++){
        int a = rand() % 128;
        int b = rand() % 1000;
        map.Insert(a, b);
    }
    map.Print();
    return 0;
}