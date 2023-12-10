#include<iostream>
#include<cmath>

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
        string typeOfHash;
    public:
        HashMapTable(string type) {
            typeOfHash = type;
            t = new HashTableEntry*[size];
            for(int i=0;i<size;i++){
                t[i] = NULL;
            }
        }
        int HashFunc(int k) {
            if(typeOfHash == "div"){
                return k % size;
            }else if(typeOfHash == "mul"){
                double c = 0.5;
                double intergerPart;
                double x = k*c;
                double frac = modf(x,&intergerPart);
                frac *= size;
                frac = floor(frac);
                return (int)frac % size;
            }else if(typeOfHash == "mid"){
                int value = k*k;
                return value % size;
            }else if(typeOfHash == "fold"){
                int val1 = k%10;
                int val2 = (k/10)%10;
                int val3 = (k/100)%10;
                return ((val1+val2+val3)%size);
            }else if(typeOfHash == "rad"){
                return ((k/10)%size);
            }
            return 0;
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
    cout<<"USING DIVISION HASHING: "<<endl;
    HashMapTable HMT1("div");
    for(int i=15;i<25;i++){
        HMT1.Insert(i+8,i);
    }
    HMT1.traverse();
    //Search for he index of key = 17
    cout<<"Key found at "<<HMT1.SearchKey(25)<<endl;
    //Remove key 32 having value 24
    HMT1.Remove(32);
    cout<<"AFTER REMOVAL : "<<endl;
    HMT1.traverse();
    cout<<"USING MULTIPLICATION HASHING: "<<endl;
    HashMapTable HMT2("mul");
    for(int i=15;i<25;i++){
        HMT2.Insert(i+8,i);
    }
    HMT2.traverse();
    //Search for he index of key = 17
    cout<<"Key found at "<<HMT2.SearchKey(25)<<endl;
    //Remove key 32 having value 24
    HMT2.Remove(32);
    cout<<"AFTER REMOVAL : "<<endl;
    HMT2.traverse();
    cout<<"USING MID_SQUARE HASHING: "<<endl;
    HashMapTable HMT3("mid");
    for(int i=15;i<25;i++){
        HMT3.Insert(i+8,i);
    }
    HMT3.traverse();
    //Search for he index of key = 17
    cout<<"Key found at "<<HMT3.SearchKey(25)<<endl;
    //Remove key 32 having value 24
    HMT3.Remove(32);
    cout<<"AFTER REMOVAL : "<<endl;
    HMT3.traverse();
    cout<<"USING FOLDING HASHING: "<<endl;
    HashMapTable HMT4("fold");
    for(int i=15;i<25;i++){
        HMT4.Insert(i+8,i);
    }
    HMT4.traverse();
    //Search for he index of key = 17
    cout<<"Key found at "<<HMT4.SearchKey(25)<<endl;
    //Remove key 32 having value 24
    HMT4.Remove(32);
    cout<<"AFTER REMOVAL : "<<endl;
    HMT4.traverse();
    cout<<"USING Radix HASHING: "<<endl;
    HashMapTable HMT5("rad");
    for(int i=15;i<25;i++){
        HMT5.Insert(i+8,i);
    }
    HMT5.traverse();
    //Search for he index of key = 17
    cout<<"Key found at "<<HMT5.SearchKey(25)<<endl;
    //Remove key 32 having value 24
    HMT5.Remove(32);
    cout<<"AFTER REMOVAL : "<<endl;
    HMT5.traverse();
}