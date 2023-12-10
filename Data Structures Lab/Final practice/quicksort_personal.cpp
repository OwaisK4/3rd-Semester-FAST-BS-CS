#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

int Partition(vector<int>& array, int start, int end){
    // int pivot = array[end];
    int pivot = array.at(end);
    int pIndex = start;
    for (int i=start; i<end; i++){
        if (array.at(i) < pivot){
            swap<int>(array.at(i), array.at(pIndex));
            pIndex++;
        }
    }
    swap<int>(array.at(end), array.at(pIndex));
    return pIndex;
}

void QuickSort(vector<int>& array, int start, int end){
    if (start < end){
        int p = Partition(array, start, end);
        QuickSort(array, start, (p-1));
        QuickSort(array, (p+1), end);
    }
}

void Merge(vector<int>& array, int start, int mid, int end){
    int i = start;
    int j = mid + 1;

    // int k = start;
    vector<int> temp;

    while (i <= mid && j <= end){
        if (array.at(i) <= array.at(j)){
            temp.push_back(array.at(i));
            i++;
            // k++;
        }
        else{
            temp.push_back(array.at(i));
            j++;
        }
    }
    while (i <= mid){
        temp.push_back(array.at(i));
        i++;
    }
    while (j <= end){
        temp.push_back(array.at(j));
        j++;
    }
    array.erase(array.begin() + start, array.begin() + end);
    array.insert(array.begin() + start, temp.begin(), temp.end());
    // array.assign(temp.begin() + start, temp.begin() + end);
}

void MergeSort(vector<int>& array, int start, int end){
    if (start < end){
        int mid = (start + end) / 2;
        MergeSort(array, start, mid);
        MergeSort(array, mid+1, end);
        Merge(array, start, mid, end);
    }
}

int main(){
    srand(time(0));
    vector<int> array;
    for (int i=0; i<10; i++){
        int x = (float) rand() / RAND_MAX * 50.0;
        array.push_back(x);
    }
    cout << "Unsorted vector: ";
    for (int it : array){
        cout << it << " ";
    }
    // QuickSort(array, 0, array.size()-1);
    MergeSort(array, 0, array.size()-1);
    cout << "\nSorted vector: ";
    for (int it : array){
        cout << it << " ";
    }

    return 0;
}