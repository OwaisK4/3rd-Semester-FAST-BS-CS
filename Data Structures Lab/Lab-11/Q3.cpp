#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<stdlib.h>
using namespace std;
#define size 10
class HashTableEntry {
    public:
        int k;
        string v;
        HashTableEntry(int k, string v) {
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
        int HashFunc(int s) {
            return (s % size);
        }
        void Insert(int k, string v) {
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
        bool isEmpty(){
            if(count == 0){
                return true;
            }
            return false;
        }
        int getContactBookSize(){
            return count;
        }
};

int main(){
    HashMapTable HMT;
    int s;
    string v;
    for(int i=0;i<5;i++){

        cout<<"Enter ID: ";
        cin>>s;
        cout<<"Enter number: ";
        cin>>v;
        HMT.Insert(s,v);
    }
    if(HMT.isEmpty()){
        cout<<"empty"<<endl;
    }else{
        cout<<"Not Empty"<<endl;
    }
    cout<<"Size of contact book: "<<HMT.getContactBookSize()<<endl;
    cout<<"Enter the student ID to search: ";
    cin>>s;
    cout<<"Pair found at index: "<<HMT.SearchKey(s)<<endl;
    cout<<"Enter the pair to be deleted: ";
    cin>>s;
    HMT.Remove(s);
    cout<<"Size of contact book: "<<HMT.getContactBookSize()<<endl;
    HMT.traverse();
}