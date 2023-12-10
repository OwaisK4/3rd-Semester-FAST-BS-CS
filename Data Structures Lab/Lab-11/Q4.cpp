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
        HashTableEntry* next;
        HashTableEntry(int k, string v) {
            next = NULL;
            this->k= k;
            this->v = v;
        }
        HashTableEntry(){
            next = NULL;
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
            count++;
            int insertPosition = HashFunc(k);
            HashTableEntry *newEntry = new HashTableEntry(k,v);
            if(t[insertPosition] == NULL){
                t[insertPosition] = newEntry;
                cout<<"Entry added. "<<endl;
                return;
            }else{
                HashTableEntry* temp = t[insertPosition];
                while(temp->next!=NULL){
                    temp = temp->next;
                }
                temp->next = newEntry;
            }
        }
        int SearchKey(int k) {
            int searchPosition = HashFunc(k);
            HashTableEntry* temp = t[searchPosition];
            while(temp!=NULL){
                if(temp->k == k){
                    return searchPosition;
                }
                temp = temp->next;
            }
            return -1;
        }
        void Remove(int k) {
            int removePosition = SearchKey(k);
            if(removePosition == -1){
                cout<<"Key doesnt exist"<<endl;
                return ;
            }else{
                count--;
                HashTableEntry* temp = t[removePosition];
                if(temp->k == k){
                    HashTableEntry* temp1 = t[removePosition];
                    t[removePosition] = t[removePosition]->next;
                    delete temp;
                    temp = NULL;
                    return;
                }else{
                    while(temp->next->k != k){
                        temp = temp->next;
                    }
                     HashTableEntry* temp1 = temp;
                     temp->next = temp->next->next;
                     delete temp1;
                     temp1 = NULL;
                     return;
                }
            }
        }
        void traverse(){
            cout<<" K   V"<<endl;
            for(int i=0;i<size;i++){
                if(t[i] != NULL){
                    HashTableEntry* temp = t[i];
                    while(temp != NULL){
                        cout<<temp->k<<"    "<<temp->v<<endl;
                        temp = temp->next;
                    }
                }
            }
        }
        ~HashMapTable() {
            for(int i=0;i<size;i++){
                if(t[i] != NULL){
                    HashTableEntry* temp = t[i];
                    while(temp!=NULL){
                        HashTableEntry* temp1 = temp->next;
                        delete temp;
                        temp = NULL;
                        temp = temp1;
                    }
                }
            }
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