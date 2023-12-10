#include<iostream>
using namespace std;
#define size 10
class HashTableEntry {
    public:
        int k;
        int v;
        HashTableEntry(int k, int v) {
        this->k= k;
        this->v = v;
        }
        HashTableEntry(){
        }
};
class HashMapTable {
    private:
        HashTableEntry **t;
        int count = 0;
    public:
        HashMapTable() {
            t = new HashTableEntry*[size];
            for(int i=0;i<size;i++){
                t[i] = NULL;
            }
        }
        int HashFunc(int k) {
            return (k%size);
        }
        void Insert(int k, int v) {
            int insertPosition = HashFunc(k);
            HashTableEntry *newEntry = new HashTableEntry(k,v);
            if(count>=10){
                cout<<"Hash Table is Already Full. "<<endl;
                return;
            }
            count++;
            if(t[insertPosition] == NULL){
                t[insertPosition] = newEntry;
                cout<<"Entry added. "<<endl;
                return;
            }
            for(int i=0;i<size;i++){
                if(t[insertPosition%size] != NULL){
                    insertPosition++;
                    continue;
                }else{
                    t[insertPosition%size] = newEntry;
                    cout<<"Entry added. "<<endl;
                    return;
                }
                
            }
        }
        int SearchKey(int k) {
            int searchPosition = HashFunc(k);
            for(int i=0;i<size;i++){
                if(t[searchPosition % size]->k == k){
                    return searchPosition % size;
                }else{
                    searchPosition++;
                }
            }
            return -1;
        }
        void Remove(int k) {
            int removePosition = SearchKey(k);
            if(removePosition == -1){
                cout<<"Key doesnt exist"<<endl;
                return ;
            }
            count--;
            delete t[removePosition];
            t[removePosition] = NULL;
        }
        void traverse(){
            cout<<" K   V"<<endl;
            for(int i=0;i<size;i++){
                if(t[i] != NULL){
                    cout<<t[i]->k<<"-->"<<t[i]->v<<endl;
                }
            }
        }
        ~HashMapTable() {
            delete []t;
            t = NULL;
        }
};
int main(){
    HashMapTable HMT;
    for(int i=15;i<25;i++){
        HMT.Insert(i+8,i);
    }
    HMT.traverse();
    //Search for he index of key = 17
    cout<<"Key found at "<<HMT.SearchKey(25)<<endl;
    //Remove key 32 having value 24
    HMT.Remove(32);
    HMT.traverse();
}