#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<int> Sort(vector<pair<int, int>> intervalArray){
    vector<int> differences;
    vector<int> index;
    int count = 0;
    for (auto it : intervalArray){
        differences.push_back(it.second - it.first);
        index.push_back(count);
        count++;
    }
    for (int i=0; i<intervalArray.size() - 1; i++){
        for (int j=0; j<intervalArray.size() - 1; j++){
            if (differences[j] > differences[j+1]){
                swap(differences[j], differences[j+1]);
                swap(index[j], index[j+1]);
            }
        }
    }
    return index;
}

vector<int> Conflicts(vector<pair<int, int>> intervalArray){

}

int main(){
    vector<pair<int, int>> intervals;
    intervals.push_back({2, 4});
    intervals.push_back({5, 9});
    intervals.push_back({10, 12});
    intervals.push_back({3, 9});
    intervals.push_back({7, 11});
    vector<int> SortedInterval = Sort(intervals);
    for (auto it : SortedInterval){
        cout << it << " ";
    }
    return 0;
}

// IntervalArray = {(2,4), (5,9), (10,12), (3,9), (7,11)}
// SortedInterval = {0, 2, 1, 4, 3}
// NoOfConflictInSortedIntervals ={ 1, 1, 2, 3, 3}